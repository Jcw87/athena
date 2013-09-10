// This file is part of libZelda.
//
// libZelda is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// libZelda is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with libZelda.  If not, see <http://www.gnu.org/licenses/>

#ifndef ZQUEST_HPP
#define ZQUEST_HPP

#include "Types.hpp"
#include <string>
#include <vector>

namespace zelda
{
/*!
 * \brief The ZQuest class
 */
class ZQuestFile
{
public:
    /*!
     * \brief The current major version of the ZQuest format
     */
    static const Uint32 Major;
    /*!
     * \brief The current minor version of the ZQuest format
     */
    static const Uint32 Minor;
    /*!
     * \brief The current revision of the ZQuest format
     */
    static const Uint32 Revision;
    /*!
     * \brief The current build of the ZQuest format
     */
    static const Uint32 Build;
    /*!
     * \brief The current version of the ZQuest format
     */
    static const Uint32 Version;

    /*!
     * \brief The magic number used to identify the file e.g. "ZQS1"
     */
    static const Uint32 Magic;

    /*!
     * \enum Game
     * \brief The list of games currently supported by ZQuest
     */
    enum Game
    {
        NoGame, //!< None or Unsupported
        LoZ,    //!< Legend of Zelda
        AoL,    //!< Adventure of Link
        ALttP,  //!< A Link to the Past
        LA,     //!< Links Awakening
        OoT,    //!< Ocarin of Time
        OoT3D,  //!< Ocarina of Time 3D
        MM,     //!< Majora's Mask
        OoS,    //!< Oracle of Season
        OoA,    //!< Oracle of Ages
        FS,     //!< Four Swords
        WW,     //!< Wind Waker
        FSA,    //!< Four Swords Adventures
        MC,     //!< Minish Cap
        TP,     //!< Twilight Princess
        PH,     //!< Phantom Hourglass
        ST,     //!< Spirit Tracks
        SS,     //!< Skyward Sword
        ALBW,   //!< A Link Between Worlds
        // Add more games here

        // This must always be last
        GameCount //!< Total number of supported games
    };

    /*!
     * \brief ZQuest
     */
    ZQuestFile();

    /*!
     * \brief ZQuest
     * \param game
     * \param endian
     * \param data
     * \param length
     */
    ZQuestFile(Game game, Endian endian, Uint8* data, Uint32 length);
    ~ZQuestFile();

    /*!
     * \brief setGame
     * \param game
     */
    void setGame(Game game);

    /*!
     * \brief game
     * \return
     */
    Game game() const;

    /*!
     * \brief setEndian
     * \param endian
     */
    void setEndian(Endian endian);

    /*!
     * \brief endian
     * \return
     */
    Endian endian() const;

    /*!
     * \brief setData
     * \param data   The data to assign
     * \param length The length of the data
     */
    void setData(Uint8* data, Uint32 length);

    /*!
     * \brief data
     * \return
     */
    Uint8* data() const;

    /*!
     * \brief length
     * \return
     */
    Uint32 length() const;

    /*!
     * \brief gameString
     * \return
     */
    std::string gameString() const;
private:
    Game   m_game;
    Endian m_endian;
    Uint8* m_data;
    Uint32 m_length;

    // Game strings support
    std::vector<std::string> m_gameStrings;
    void initGameStrings();
};
} // zelda

#endif // ZQUEST_HPP