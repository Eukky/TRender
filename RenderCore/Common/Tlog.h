#ifndef _TRENDER_COMMON_TLOG_H_
#define _TRENDER_COMMON_TLOG_H_

#include <spdlog/spdlog.h>

namespace TRender {
    namespace Common {
        class Tlog {
        public:
            Tlog();
            virtual ~Tlog();
            static bool Init();

            inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
            inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

        private:
            static std::shared_ptr<spdlog::logger> s_CoreLogger;
            static std::shared_ptr<spdlog::logger> s_ClientLogger;
        };

    }
    
}

#define TR_CORE_TRACE(...) ::TRender::Common::Tlog::GetCoreLogger()->trace(__VA_ARGS__)
#define TR_CORE_INFO(...) ::TRender::Common::Tlog::GetCoreLogger()->info(__VA_ARGS__)
#define TR_CORE_WARN(...) ::TRender::Common::Tlog::GetCoreLogger()->warn(__VA_ARGS__)
#define TR_CORE_ERROR(...) ::TRender::Common::Tlog::GetCoreLogger()->error(__VA_ARGS__)
#define TR_CORE_CRITICAL(...) ::TRender::Common::Tlog::GetCoreLogger()->critical(__VA_ARGS__)

#define TR_CLIENT_TRACE(...) ::TRender::Common::Tlog::GetClientLogger()->trace(__VA_ARGS__)
#define TR_CLIENT_INFO(...) ::TRender::Common::Tlog::GetClientLogger()->info(__VA_ARGS__)
#define TR_CLIENT_WARN(...) ::TRender::Common::Tlog::GetClientLogger()->warn(__VA_ARGS__)
#define TR_CLIENT_ERROR(...) ::TRender::Common::Tlog::GetClientLogger()->error(__VA_ARGS__)
#define TR_CLIENT_CRITICAL(...) ::TRender::Common::Tlog::GetClientLogger()->critical(__VA_ARGS__)

#endif //_TRENDER_COMMON_TLOG_H_