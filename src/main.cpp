#include <psdk_core.h>           // PSDK entry point
#include <gpiod.h>               // libgpiod
#include <iostream>

constexpr unsigned GPIO_LINE = 17;          // BCM17 / pin 11

gpiod_chip  *chip;
gpiod_line  *line;

// Callback when the Pilot app toggles a widget switch
void OnLightCommand(bool onOff)
{
    gpiod_line_set_value(line, onOff ? 1 : 0);
}

int main(int argc, char **argv)
{
    // ----- GPIO setup -----
    chip = gpiod_chip_open_by_name("gpiochip0");
    line = gpiod_chip_get_line(chip, GPIO_LINE);
    gpiod_line_request_output(line, "psdk-light", 0);

    // ----- PSDK init -----
    DjiReturnCode ret = DjiCore_Init();
    if (ret != DJI_ERROR_SYSTEM_MODULE_CODE_SUCCESS) {
        std::cerr << "PSDK init failed\n";
        return -1;
    }

    // Register your callback (pseudo-API; depends on widget you expose)
    DjiCore_RegSwitchCallback("searchlight", OnLightCommand);

    // Hand over to the SDK event loop
    while (true) {
        DjiCore_ProcessEvents();
    }
}
