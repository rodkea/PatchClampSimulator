#include "second_core.h"

using namespace std;

const uint32_t COMANDO_INICIO {12};
const uint32_t COMANDO_PARAR {13};
const int32_t DELAY_MS = {1}; // NEGATIVO VER EXPLICACION UN LA FUNCION ADD_REPETING_TIMER_MS
array<FloatBytes,4> funcs;
char package_number {0}; 
CircularBuffer dataBuffer(255);

void second_core_main()
{   
  
  struct repeating_timer timer;
  bool isTimerStarted {false};
  while(true) {
        if( multicore_fifo_rvalid()) {  
            read_command(multicore_fifo_pop_blocking(), isTimerStarted, timer);                 
        }
        if (!dataBuffer.empty()) { 
            uint32_t interrupt_status = save_and_disable_interrupts();
            uart_putc_raw(uart0, dataBuffer.pop());            
            restore_interrupts(interrupt_status);
          }   
  }
}

void read_command(uint32_t command,bool & isTimerStarted, struct repeating_timer& timer)
{  
  switch (command)
  {
    case 12: 
      if( !isTimerStarted) {
        isTimerStarted = add_repeating_timer_ms(DELAY_MS, repeating_timer_callback, NULL, &timer); 
        cout << "TIMER STARTED" << endl;
      } else {
        cout << "TIMER ALREADY STARTED" << endl;
      }
      break;
    case 13:   
      if( isTimerStarted) {
        isTimerStarted = !cancel_repeating_timer(&timer);
        cout << "TIMER STOPPED" << endl;
      } else {
        cout << "TIMER ISN'T STARTED" << endl;
      }     
      
      break;
    default:
      cout << "WRONG COMMAND: " << command << endl;
      break;
  }      
}

bool repeating_timer_callback(struct repeating_timer *t)
{  
  package_number ++;
  generate_functions(funcs,to_ms_since_boot(get_absolute_time()) );
  package_queue(funcs, package_number);
  // send_package( funcs, package_number);
  return true;
}

void generate_functions(array<FloatBytes,4>& funcs, uint32_t t) {
  funcs[0].value = sine_wave(t);
  funcs[1].value = cosine_wave(t);
  funcs[2].value = square_wave(t);
  funcs[3].value = triangular_wave(t);
}


void package_queue(array<FloatBytes,4>& funcs, char package_number)
{
  dataBuffer.push('A'); // Start of package indicator.
  for(FloatBytes& func : funcs) {
    for(char& c : func.bytes) {
      dataBuffer.push(c); //Queue each byte of the function value.
    }
  }
  dataBuffer.push(package_number); // Queue the package number.
  dataBuffer.push('Z'); // End of package indicator.
}