/**
 * listener.cpp – minimalist “wire-tap” that shows every byte the Payload-SDK
 * receives from the aircraft.  Works on any payload board (Pi Zero 2 W here).
 *
 * Build: see root-level CMakeLists.txt    Run: sudo ./listener
 *
 * NOTE: This relies only on the generic data-link API in PSDK ≥ v3.7.
 *       Replace `kDataChannel0` with the bulk channel you actually use,
 *       or register multiple callbacks if needed.
 */

#include <dji_core.h>
#include <dji_aircraft_info.h>
#include <dji_linker.h>
#include <cstdio>
#include <cstring>

static void dataCallback(const uint8_t *buf, uint16_t len, void *userData)
{
    printf("[PSDK] %u bytes  : ", len);
    for (uint16_t i = 0; i < len; ++i)
        printf("%02X ", buf[i]);
    printf("\n");
    fflush(stdout);
}

int main(int argc, char **argv)
{
    // ---------------------------------------------------------------------
    // 1.  Initialise the Payload SDK core (blocking until negotiation ends)
    // ---------------------------------------------------------------------
    DjiReturnCode rc = DjiCore_Init();
    if (rc != DJI_ERROR_SYSTEM_MODULE_CODE_SUCCESS) {
        printf("DjiCore_Init failed (%d)\n", rc);
        return -1;
    }

    // ---------------------------------------------------------------------
    // 2.  Register a raw-byte listener on data channel 0
    // ---------------------------------------------------------------------
    rc = DjiLinker_RegRecvCallback(kDataChannel0, dataCallback, nullptr);
    if (rc != DJI_ERROR_SYSTEM_MODULE_CODE_SUCCESS) {
        printf("RegRecvCallback failed (%d)\n", rc);
        return -1;
    }

    printf("Listener ready – printing everything arriving on channel 0 …\n");

    // ---------------------------------------------------------------------
    // 3.  Idle loop – the SDK spawns its own threads, just keep main alive
    // ---------------------------------------------------------------------
    while (true)
        sleep(1);

    // (Never reached, but good practice:)
    DjiCore_DeInit();
    return 0;
}
