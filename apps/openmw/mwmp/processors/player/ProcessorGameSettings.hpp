#ifndef OPENMW_PROCESSORGAMESETTINGS_HPP
#define OPENMW_PROCESSORGAMESETTINGS_HPP

#include "apps/openmw/mwbase/environment.hpp"
#include "apps/openmw/mwworld/worldimp.hpp"
#include "apps/openmw/mwgui/windowmanagerimp.hpp"

#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorGameSettings final: public PlayerProcessor
    {
    public:
        ProcessorGameSettings()
        {
            BPP_INIT(ID_GAME_SETTINGS)
        }

        virtual void Do(PlayerPacket &packet, BasePlayer *player)
        {
            static const int initialLogLevel = Log::GetLevel();

            if (isLocal())
            {
                LOG_MESSAGE_SIMPLE(Log::LOG_INFO, "Received ID_GAME_SETTINGS");

                if (MWBase::Environment::get().getWindowManager()->isGuiMode())
                {
                    if (MWBase::Environment::get().getWindowManager()->getMode() == MWGui::GM_Console && !player->consoleAllowed)
                        MWBase::Environment::get().getWindowManager()->popGuiMode();
                    else if (MWBase::Environment::get().getWindowManager()->getMode() == MWGui::GM_Rest &&
                        (!player->bedRestAllowed || !player->wildernessRestAllowed || !player->waitAllowed))
                        MWBase::Environment::get().getWindowManager()->popGuiMode();
                }

                if (player->enforcedLogLevel > -1)
                {
                    LOG_APPEND(Log::LOG_INFO, "- server is enforcing log level %i", player->enforcedLogLevel);
                    
                    Log::Get().SetLevel(player->enforcedLogLevel);
                }
                else if (initialLogLevel != Log::GetLevel())
                {
                    LOG_APPEND(Log::LOG_INFO, "- log level has been reset to initial value %i", initialLogLevel);
                    Log::Get().SetLevel(initialLogLevel);
                }

                MWBase::Environment::get().getWorld()->setPhysicsFramerate(player->physicsFramerate);
            }
        }
    };
}

#endif //OPENMW_PROCESSORGAMESETTINGS_HPP
