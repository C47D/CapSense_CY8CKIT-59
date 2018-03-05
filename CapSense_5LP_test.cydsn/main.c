#include "project.h"

int main(void)
{
    CyGlobalIntEnable;

    CapSense_Start();
    
    CapSense_InitializeAllBaselines();

    while (1) {
        
        CapSense_UpdateEnabledBaselines();
        CapSense_ScanEnabledWidgets();
        
        while(CapSense_IsBusy());
        
        if (CapSense_CheckIsWidgetActive(CapSense_BUTTON0__BTN)) {
            LED_Write(1);
        } else if (CapSense_CheckIsWidgetActive(CapSense_BUTTON1__BTN)) {
            LED_Write(0);
        } else if (CapSense_CheckIsWidgetActive(CapSense_BUTTON2__BTN)) {
            LED_Write(1);
            CyDelay(250);
            LED_Write(0);
            CyDelay(250);
        }
    }
}

/* [] END OF FILE */
