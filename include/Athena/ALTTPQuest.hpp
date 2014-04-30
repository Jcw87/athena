// This file is part of libAthena.
//
// libAthena is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// libAthena is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with libAthena.  If not, see <http://www.gnu.org/licenses/>

#ifndef __ALTTP_QUEST_HPP__
#define __ALTTP_QUEST_HPP__

#include "Types.hpp"
#include <string>
#include <vector>
#include "ALTTPStructs.hpp"
#include "ALTTPEnums.hpp"

namespace Athena
{

/*! \class ALTTPQuest
 *  \brief A Link to the Past Quest container class
 *
 * Contains all relevant data for an A Link to the Past
 * Quest entry.
 */
class ALTTPQuest
{
public:
    /*!
     * \brief ALTTPQuest
     */
    ALTTPQuest();
    ~ALTTPQuest();

    /*!
     * \brief setRoomFlags
     * \param flags
     */
    void setRoomFlags(std::vector<ALTTPRoomFlags*> flags);

    /*!
     * \brief setRoomFlags
     * \param rf
     * \param id
     */
    void setRoomFlags(ALTTPRoomFlags* rf, Uint32 id);

    /*!
     * \brief roomFlags
     * \return
     */
    std::vector<ALTTPRoomFlags*> roomFlags();

    /*!
     * \brief roomFlags
     * \param id
     * \return
     */
    ALTTPRoomFlags* roomFlags(Uint32 id);

    /*!
     * \brief setOverworldEvents
     * \param events
     */
    void setOverworldEvents(std::vector<ALTTPOverworldEvent*> events);

    /*!
     * \brief setOverworldEvents
     * \param ow
     * \param id
     */
    void setOverworldEvents(ALTTPOverworldEvent* ow, Uint32 id);

    /*!
     * \brief overworldEvents
     * \return
     */
    std::vector<ALTTPOverworldEvent*> overworldEvents() const;

    /*!
     * \brief overworldEvent
     * \param id
     * \return
     */
    ALTTPOverworldEvent* overworldEvent(Uint32 id) const;

    /*!
     * \brief setInventory
     * \param inv
     */
    void setInventory(ALTTPInventory* inv);

    /*!
     * \brief inventory
     * \return
     */
    ALTTPInventory* inventory() const;

    /*!
     * \brief setRupeeMax
     * \param val
     */
    void setRupeeMax(Uint16 val);

    /*!
     * \brief rupeeMax
     * \return
     */
    Uint16  rupeeMax() const;

    /*!
     * \brief setRupeeCurrent
     * \param val
     */
    void setRupeeCurrent(Uint16 val);

    /*!
     * \brief rupeeCurrent
     * \return
     */
    Uint16  rupeeCurrent() const;

    /*!
     * \brief setCompasses
     * \param flags
     */
    void setCompasses(ALTTPDungeonItemFlags flags);

    /*!
     * \brief compasses
     * \return
     */
    ALTTPDungeonItemFlags compasses() const;

    /*!
     * \brief setBigKeys
     * \param flags
     */
    void setBigKeys(ALTTPDungeonItemFlags flags);

    /*!
     * \brief bigKeys
     * \return
     */
    ALTTPDungeonItemFlags bigKeys() const;

    /*!
     * \brief setDungeonMaps
     * \param flags
     */
    void setDungeonMaps(ALTTPDungeonItemFlags flags);

    /*!
     * \brief dungeonMaps
     * \return
     */
    ALTTPDungeonItemFlags dungeonMaps() const;

    /*!
     * \brief setWishingPond
     * \param val
     */
    void setWishingPond(Uint16 val);

    /*!
     * \brief wishingPond
     * \return
     */
    Uint16 wishingPond() const;

    /*!
     * \brief setHealthMax
     * \param val
     */
    void setHealthMax(Uint8 val);

    /*!
     * \brief healthMax
     * \return
     */
    Uint8   healthMax() const;

    /*!
     * \brief setHealth
     * \param val
     */
    void setHealth(Uint8 val);

    /*!
     * \brief health
     * \return
     */
    Uint8   health() const;

    /*!
     * \brief setMagicPower
     * \param val
     */
    void setMagicPower(Uint8 val);

    /*!
     * \brief magicPower
     * \return
     */
    Uint8  magicPower() const;

    /*!
     * \brief setKeys
     * \param val
     */
    void setKeys(Uint8 val);

    /*!
     * \brief keys
     * \return
     */
    Uint8   keys() const;

    /*!
     * \brief setBombUpgrades
     * \param val
     */
    void setBombUpgrades(Uint8 val);

    /*!
     * \brief bombUpgrades
     * \return
     */
    Uint8   bombUpgrades() const;

    /*!
     * \brief setArrowUpgrades
     * \param val
     */
    void setArrowUpgrades(Uint8 val);

    /*!
     * \brief arrowUpgrades
     * \return
     */
    Uint8   arrowUpgrades() const;

    /*!
     * \brief setHealthFiller
     * \param val
     */
    void setHealthFiller(Uint8 val);

    /*!
     * \brief healthFiller
     * \return
     */
    Uint8   healthFiller() const;

    /*!
     * \brief setMagicFiller
     * \param val
     */
    void setMagicFiller(Uint8 val);

    /*!
     * \brief magicFiller
     * \return
     */
    Uint8   magicFiller() const;

    /*!
     * \brief setPendants
     * \param val
     */
    void setPendants(ALTTPPendants val);

    /*!
     * \brief pendants
     * \return
     */
    ALTTPPendants pendants() const;

    /*!
     * \brief setBombFiller
     * \param val
     */
    void setBombFiller(Uint8 val);

    /*!
     * \brief bombFiller
     * \return
     */
    Uint8   bombFiller() const;

    /*!
     * \brief setArrowFiller
     * \param val
     */
    void setArrowFiller(Uint8 val);

    /*!
     * \brief arrowFiller
     * \return
     */
    Uint8   arrowFiller() const;

    /*!
     * \brief setArrows
     * \param val
     */
    void setArrows(Uint8 val);

    /*!
     * \brief arrows
     * \return
     */
    Uint8   arrows() const;

    /*!
     * \brief setAbilityFlags
     * \param val
     */
    void setAbilityFlags(ALTTPAbilities val);

    /*!
     * \brief abilityFlags
     * \return
     */
    ALTTPAbilities abilityFlags() const;

    /*!
     * \brief setCrystals
     * \param val
     */
    void setCrystals(ALTTPCrystals val);\

    /*!
     * \brief crystals
     * \return
     */
    ALTTPCrystals crystals() const;

    /*!
     * \brief setMagicUsage
     * \param val
     */
    void setMagicUsage(ALTTPMagicUsage val);

    /*!
     * \brief magicUsage
     * \return
     */
    ALTTPMagicUsage magicUsage() const;

    /*!
     * \brief setDungeonKeys
     * \param val
     */
    void setDungeonKeys(std::vector<Uint8> val);

    /*!
     * \brief setDungeonKeys
     * \param id
     * \param val
     */
    void setDungeonKeys(Uint32 id, Uint8 val);

    /*!
     * \brief dungeonKeys
     * \param id
     * \return
     */
    Uint8   dungeonKeys(Uint32 id) const;

    /*!
     * \brief dungeonCount
     * \return
     */
    Uint32  dungeonCount() const;

    /*!
     * \brief setProgressIndicator
     * \param val
     */
    void setProgressIndicator(ALTTPProgressIndicator val);

    /*!
     * \brief progressIndicator
     * \return
     */
    ALTTPProgressIndicator progressIndicator() const;

    /*!
     * \brief setProgressFlags1
     * \param val
     */
    void setProgressFlags1(ALTTPProgressFlags1 val);

    /*!
     * \brief progressFlags1
     * \return
     */
    ALTTPProgressFlags1 progressFlags1() const;

    /*!
     * \brief setMapIcon
     * \param val
     */
    void setMapIcon(ALTTPMapIcon val);

    /*!
     * \brief mapIcon
     * \return
     */
    ALTTPMapIcon mapIcon() const;

    /*!
     * \brief setStartLocation
     * \param val
     */
    void setStartLocation(ALTTPStartLocation val);

    /*!
     * \brief startLocation
     * \return
     */
    ALTTPStartLocation startLocation() const;

    /*!
     * \brief setProgressFlags2
     * \param val
     */
    void setProgressFlags2(ALTTPProgressFlags2 val);

    /*!
     * \brief progressFlags2
     * \return
     */
    ALTTPProgressFlags2 progressFlags2() const;

    /*!
     * \brief setLightDarkWorldIndicator
     * \param val
     */
    void setLightDarkWorldIndicator(ALTTPLightDarkWorldIndicator val);

    /*!
     * \brief lightDarkWorldIndicator
     * \return
     */
    ALTTPLightDarkWorldIndicator lightDarkWorldIndicator() const;

    /*!
     * \brief setTagAlong
     * \param val
     */
    void setTagAlong(ALTTPTagAlong val);

    /*!
     * \brief tagAlong
     * \return
     */
    ALTTPTagAlong tagAlong() const;

    /*!
     * \brief setOldManFlags
     * \param flags
     */
    void setOldManFlags(std::vector<Uint8> flags);

    /*!
     * \brief setOldManFlag
     * \param id
     * \param val
     */
    void setOldManFlag(Uint32 id, Uint8 val);

    /*!
     * \brief oldManFlag
     * \param id
     * \return
     */
    Uint8 oldManFlag(Uint32 id);

    /*!
     * \brief oldManFlagCount
     * \return
     */
    Uint32 oldManFlagCount() const;

    /*!
     * \brief setBombFlag
     * \param flag
     */
    void setBombFlag(Uint8 flag);

    /*!
     * \brief bombFlag
     * \return
     */
    Uint8 bombFlag() const;

    /*!
     * \brief setUnknown1
     * \param flags
     */
    void setUnknown1(std::vector<Uint8> flags);

    /*!
     * \brief setUnknown1
     * \param id
     * \param val
     */
    void setUnknown1(Uint32 id, Uint8 val);

    /*!
     * \brief unknown1
     * \param id
     * \return
     */
    Uint8 unknown1(Uint32 id);

    /*!
     * \brief unknown1Count
     * \return
     */
    Uint32 unknown1Count() const;

    /*!
     * \brief setPlayerName
     * \param playerName
     */
    void setPlayerName(std::vector<Uint16> playerName);
    /*!
     * \brief setPlayerName
     * \param playerName
     */
    void setPlayerName(const std::string& playerName);
    /*!
     * \brief playerName
     * \return
     */
    std::vector<Uint16> playerName() const;
    /*!
     * \brief playerNameToString
     * \return
     */
    std::string playerNameToString() const;

    /*!
     * \brief setValid
     * \param val
     */
    void setValid(bool val);

    /*!
     * \brief valid
     * \return
     */
    bool valid();

    /*!
     * \brief setDungeonDeathTotals
     * \param val
     */
    void setDungeonDeathTotals(std::vector<Uint16> val);

    /*!
     * \brief setDungeonDeathTotal
     * \param id
     * \param val
     */
    void setDungeonDeathTotal(Uint32 id, Uint16 val);

    /*!
     * \brief dungeonDeathTotal
     * \param id
     * \return
     */
    Uint16 dungeonDeathTotal(Uint32 id) const;

    /*!
     * \brief dungeonDeathTotalCount
     * \return
     */
    Uint16 dungeonDeathTotalCount() const;

    /*!
     * \brief setUnknown2
     * \param val
     */
    void setUnknown2(Uint16 val);

    /*!
     * \brief unknown2
     * \return
     */
    Uint16 unknown2() const;

    /*!
     * \brief setDeathSaveCount
     * \param val
     */
    void setDeathSaveCount(Uint16 val);

    /*!
     * \brief deathSaveCount
     * \return
     */
    Uint16 deathSaveCount() const;

    /*!
     * \brief setPostGameDeathCounter
     * \param val
     */
    void setPostGameDeathCounter(Int16 val);

    /*!
     * \brief postGameDeathCounter
     * \return
     */
    Int16 postGameDeathCounter() const;

    /*!
     * \brief setChecksum
     * \param checksum
     */
    void setChecksum(Uint16 checksum);

    /*!
     * \brief checksum
     * \return
     */
    Uint16 checksum() const;
private:
    std::vector<ALTTPRoomFlags*>      m_roomFlags;
    std::vector<ALTTPOverworldEvent*> m_overworldEvents;
    ALTTPInventory*                   m_inventory;
    Uint16                            m_rupeeMax;
    Uint16                            m_rupeeCurrent;
    ALTTPDungeonItemFlags             m_compasses;
    ALTTPDungeonItemFlags             m_bigKeys;
    ALTTPDungeonItemFlags             m_dungeonMaps;
    Uint16                            m_wishingPond;
    Uint8                             m_healthMax;
    Uint8                             m_health;
    Uint8                             m_magicPower;
    Uint8                             m_keys;
    Uint8                             m_bombUpgrades;
    Uint8                             m_arrowUpgrades;
    Uint8                             m_heartFiller;
    Uint8                             m_magicFiller;
    ALTTPPendants                     m_pendants;
    Uint8                             m_bombFiller;
    Uint8                             m_arrowFiller;
    Uint8                             m_arrows;
    ALTTPAbilities                    m_abilityFlags;
    ALTTPCrystals                     m_crystals;
    ALTTPMagicUsage                   m_magicUsage;
    std::vector<Uint8>                m_dungeonKeys;
    ALTTPProgressIndicator            m_progressIndicator;
    ALTTPProgressFlags1               m_progressFlags1;
    ALTTPMapIcon                      m_mapIcon;
    ALTTPStartLocation                m_startLocation;
    ALTTPProgressFlags2               m_progressFlags2;
    ALTTPLightDarkWorldIndicator      m_lightDarkWorldIndicator;
    ALTTPTagAlong                     m_tagAlong;
    std::vector<Uint8>                m_oldManFlags;
    Uint8                             m_bombFlag;
    std::vector<Uint8>                m_unknown1;
    std::vector<Uint16>               m_playerName;
    Uint16                            m_valid;
    std::vector<Uint16>               m_dungeonDeathTotals;
    Uint16                            m_unknown2;
    Uint16                            m_deathSaveCount;
    Int16                             m_postGameDeathCounter;
    Uint16                            m_checksum;
};

} // zelda

#endif // __ALTTP_QUEST_HPP__