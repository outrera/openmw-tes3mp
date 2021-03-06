//
// Created by koncord on 01.04.17.
//

#ifndef OPENMW_PROCESSORPLAYERCHARGEN_HPP
#define OPENMW_PROCESSORPLAYERCHARGEN_HPP

#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorPlayerCharGen final: public PlayerProcessor
    {
    public:
        ProcessorPlayerCharGen()
        {
            BPP_INIT(ID_PLAYER_CHARGEN)
        }

        void Do(PlayerPacket &packet, const std::shared_ptr<Player> &player) override
        {
            DEBUG_PRINTF(strPacketID.c_str());

            if (player->charGenState.currentStage == player->charGenState.endStage)
                Networking::get().getState().getEventCtrl().Call<CoreEvent::ON_PLAYER_ENDCHARGEN>(player.get());
        }
    };
}

#endif //OPENMW_PROCESSORPLAYERCHARGEN_HPP
