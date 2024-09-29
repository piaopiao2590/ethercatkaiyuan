#include <math.h>
#include <stdbool.h>
#include <string.h>

#include "md_app.h"
#include "md_ethercat.h"

int main(void)
{ 
  bsp_init();
	module_init();
	while(1)
	{	
    ethercat_loop();
 	}
}