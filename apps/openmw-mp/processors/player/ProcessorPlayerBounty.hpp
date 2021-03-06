#ifndef OPENMW_PROCESSORPLAYERBOUNTY_HPP
#define OPENMW_PROCESSORPLAYERBOUNTY_HPP

#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorPlayerBounty final: public PlayerProcessor
    {
    public:
        ProcessorPlayerBounty()
        {
            BPP_INIT(ID_PLAYER_BOUNTY)
        }

        void Do(PlayerPacket &packet, const std::shared_ptr<Player> &player) override
        {
            Networking::get().getState().getEventCtrl().Call<CoreEvent::ON_PLAYER_BOUNTY>(player.get());
        }
    };
}

#endif //OPENMW_PROCESSORPLAYERBOUNTY_HPP
