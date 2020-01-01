#include "Tlog.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace TRender {
    namespace Common {
        std::shared_ptr<spdlog::logger> Tlog::s_CoreLogger;
        std::shared_ptr<spdlog::logger> Tlog::s_ClientLogger;
        Tlog::Tlog() {

        }
        Tlog::~Tlog() {

        }
        bool Tlog::Init() {
            spdlog::set_pattern("%^[%T] %n: %v%$");
            Tlog::s_CoreLogger = spdlog::stdout_color_mt("TRender");
            Tlog::s_CoreLogger->set_level(spdlog::level::trace);

            Tlog::s_ClientLogger = spdlog::stdout_color_mt("Game");
            Tlog::s_ClientLogger->set_level(spdlog::level::trace);
            return true;
        }
    }
}