#ifndef OPENMW_PROCESSORPLAYERATTACK_HPP
#define OPENMW_PROCESSORPLAYERATTACK_HPP

#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorPlayerAttack final: public PlayerProcessor
    {
        PlayerPacketController *playerController;
    public:
        ProcessorPlayerAttack()
        {
            BPP_INIT(ID_PLAYER_ATTACK)
            playerController = Networking::get().getPlayerPacketController();
        }

        void Do(PlayerPacket &packet, const std::shared_ptr<Player> &player) override
        {
            DEBUG_PRINTF(strPacketID.c_str());

            if (!player->creatureStats.mDead)
            {
                player->sendToLoaded(packet);
            }
        }
    };
}

#endif //OPENMW_PROCESSORPLAYERATTACK_HPP
