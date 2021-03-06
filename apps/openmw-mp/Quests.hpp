//
// Created by koncord on 25.08.17.
//

#pragma once

#include <cstddef>
#include <components/openmw-mp/Base/BasePlayer.hpp>
#include "BaseMgr.hpp"

class LuaState;
class Player;

class JournalItem
{
public:
    static void Init(LuaState &lua);
public:
    explicit JournalItem(mwmp::JournalItem item);
    ~JournalItem();

    std::string getQuest() const;
    void setQuest(const std::string &quest);

    int getIndex() const;
    void setIndex(int index);

    mwmp::JournalItem::Type getType() const;
    void setType(mwmp::JournalItem::Type type);

    std::string getActorRefId() const;
    void setActorRefId(const std::string &refid);


    mwmp::JournalItem item;
};

class Quests final: public BaseMgr
{
public:
    static void Init(LuaState &lua);
public:
    explicit Quests(Player *player);


    size_t getJournalChangesSize() const;
    size_t getKillChangesSize() const;

    void addJournalItem(JournalItem item);
    void setJournalItem(unsigned int id, JournalItem item);
    JournalItem getJournalItem(unsigned int id);

    void addKill(const std::string &refId, int number);
    std::tuple<std::string, int> getKill(unsigned int i) const;

private:
    void processUpdate() final;
    bool changedKills, changedJournal;
};


