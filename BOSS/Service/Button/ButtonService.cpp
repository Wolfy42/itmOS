#include "ButtonService.h"
#include "BOSSAPI/serviceCalls.h"

ButtonService::ButtonService() {
}

ButtonService::~ButtonService() {
}

void ButtonService::start() {
    m_running = true;
    registerService(BUTTON_SERVICE_CALL);
}

void ButtonService::command(int params[]) {
    if (m_running) {
        while (!(m_buttonDriver.read((byte*)0x0)[0]));
    }
}
        
bool ButtonService::stop() {
    m_running = false;
    return true;
}
