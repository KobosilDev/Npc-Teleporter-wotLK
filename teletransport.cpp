/*
*********************************************************
******************* GITHUB KOBOSILDEV *******************
***************** 18 de noviembre 2022 ******************
*********************************************************
*/

#include "ScriptMgr.h"
#include "ScriptedGossip.h"
#include "Player.h"
#include "Creature.h"
#include "GossipDef.h"
#include "WorldSession.h"
#include "Chat.h"

class teletransportScript : public CreatureScript
{
public:
    teletransportScript() : CreatureScript("teletransport") {}

    struct teletransportScriptAI: public ScriptedAI
    {
        teletransportScriptAI(Creature* creature) : ScriptedAI(creature) {}

        bool OnGossipHello(Player* player) override
        {
            if (!player || !me)
                return true;

            ClearGossipMenuFor(player);
		    // Defino la ruta de la imagen y luego : y el tamaño de la imagen
            AddGossipItemFor(player, GOSSIP_ICON_TALK , "|TInterface\\icons\\spell_arcane_teleportorgrimmar:35|t|r Ciudades Horda", GOSSIP_SENDER_MAIN, 1);
            AddGossipItemFor(player, GOSSIP_ICON_TALK , "|TInterface\\icons\\spell_arcane_teleportironforge:35|t|r Ciudades Alianza", GOSSIP_SENDER_MAIN, 2);
            AddGossipItemFor(player, GossipOptionIcon::GOSSIP_ICON_TALK , "|TInterface\\icons\\spell_arcane_teleportshattrath:35|t|r Terrallente", GOSSIP_SENDER_MAIN, 3);
            AddGossipItemFor(player, GossipOptionIcon::GOSSIP_ICON_TALK , "|TInterface\\icons\\spell_arcane_teleportdalaran:35|t|r Rasganorte", GOSSIP_SENDER_MAIN, 4);
            // AddGossipItemFor(player, GossipOptionIcon::GOSSIP_ICON_INTERACT_1 , "|CFF800080[Cerrar]|r", GOSSIP_SENDER_MAIN, 99);
            SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);

            if (!player || !me)
                return true;

            ClearGossipMenuFor(player);

            switch(action)
            {
                case 0: // Volver atras
                    ClearGossipMenuFor(player);
                    OnGossipHello(player); 
                    break;

                case 1: // CIUDADES HORDA
                    AddGossipItemFor(player, GOSSIP_ICON_TALK , "|TInterface\\icons\\spell_arcane_teleportorgrimmar:35|t|r Orgrimmar", GOSSIP_SENDER_MAIN, 5);
                    AddGossipItemFor(player, GOSSIP_ICON_TALK , "|TInterface\\icons\\spell_arcane_teleportthunderbluff:35|t|r Cima del Trueno", GOSSIP_SENDER_MAIN, 6);
                    AddGossipItemFor(player, GOSSIP_ICON_TALK , "|TInterface\\icons\\spell_arcane_teleportundercity:35|t|r Entrañas", GOSSIP_SENDER_MAIN, 7);
                    AddGossipItemFor(player, GOSSIP_ICON_TALK , "|TInterface\\icons\\spell_arcane_teleportsilvermoon:35|t|r Lunargenta", GOSSIP_SENDER_MAIN, 8);
                    AddGossipItemFor(player, GossipOptionIcon::GOSSIP_ICON_TALK , "|CFF800080[Atras]|r", GOSSIP_SENDER_MAIN, 0);
                    SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                    break;

                case 2: // CIUDADES ALIANZA
                    AddGossipItemFor(player, GOSSIP_ICON_TALK , "|TInterface\\icons\\spell_arcane_teleportstormwind:35|t|r Ventormenta", GOSSIP_SENDER_MAIN, 9);
                    AddGossipItemFor(player, GOSSIP_ICON_TALK , "|TInterface\\icons\\spell_arcane_teleportironforge:35|t|r Forjaz", GOSSIP_SENDER_MAIN, 10);
                    AddGossipItemFor(player, GOSSIP_ICON_TALK , "|TInterface\\icons\\spell_arcane_teleportdarnassus:35|t|r Darnassus", GOSSIP_SENDER_MAIN, 11);
                    AddGossipItemFor(player, GOSSIP_ICON_TALK , "|TInterface\\icons\\spell_arcane_teleportexodar:35|t|r El Exodar", GOSSIP_SENDER_MAIN, 12);
                    AddGossipItemFor(player, GossipOptionIcon::GOSSIP_ICON_TALK , "|CFF800080[Atras]|r", GOSSIP_SENDER_MAIN, 0);
                    SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                    break;

                case 3: // TERRALLENTE
                    AddGossipItemFor(player, GossipOptionIcon::GOSSIP_ICON_TALK , "Península del Fuego Infernal", GOSSIP_SENDER_MAIN, 13);
                    AddGossipItemFor(player, GossipOptionIcon::GOSSIP_ICON_TALK , "Marisma de Zangar", GOSSIP_SENDER_MAIN, 14);
                    AddGossipItemFor(player, GossipOptionIcon::GOSSIP_ICON_TALK , "Nagrand", GOSSIP_SENDER_MAIN, 15);
                    AddGossipItemFor(player, GossipOptionIcon::GOSSIP_ICON_TALK , "Montañas Filospada", GOSSIP_SENDER_MAIN, 16);
                    AddGossipItemFor(player, GossipOptionIcon::GOSSIP_ICON_TALK , "Tormenta Abisal", GOSSIP_SENDER_MAIN, 17);
                    AddGossipItemFor(player, GossipOptionIcon::GOSSIP_ICON_TALK , "Bosque de Terokkar", GOSSIP_SENDER_MAIN, 18);
                    AddGossipItemFor(player, GossipOptionIcon::GOSSIP_ICON_TALK , "Valle Sombraluna", GOSSIP_SENDER_MAIN, 19);
                    AddGossipItemFor(player, GossipOptionIcon::GOSSIP_ICON_TALK , "|CFF800080[Atras]|r", GOSSIP_SENDER_MAIN, 0);
                    SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                    break;

                case 4: // RASGANORTE
                    AddGossipItemFor(player, GossipOptionIcon::GOSSIP_ICON_TALK , "Dalaran", GOSSIP_SENDER_MAIN, 20);
                    AddGossipItemFor(player, GossipOptionIcon::GOSSIP_ICON_TALK , "Cementerio de Dragones", GOSSIP_SENDER_MAIN, 21);
                    AddGossipItemFor(player, GossipOptionIcon::GOSSIP_ICON_TALK , "Fiordo Aquilonal", GOSSIP_SENDER_MAIN, 22);
                    AddGossipItemFor(player, GossipOptionIcon::GOSSIP_ICON_TALK , "Tundra Boreal", GOSSIP_SENDER_MAIN, 23);
                    AddGossipItemFor(player, GossipOptionIcon::GOSSIP_ICON_TALK , "Cuenca de Sholazar", GOSSIP_SENDER_MAIN, 24);
                    AddGossipItemFor(player, GossipOptionIcon::GOSSIP_ICON_TALK , "Colinas Pardas", GOSSIP_SENDER_MAIN, 25);
                    AddGossipItemFor(player, GossipOptionIcon::GOSSIP_ICON_TALK , "Zul'drak", GOSSIP_SENDER_MAIN, 26);
                    AddGossipItemFor(player, GossipOptionIcon::GOSSIP_ICON_TALK , "Cumbres Tormentosas", GOSSIP_SENDER_MAIN, 27);
                    AddGossipItemFor(player, GossipOptionIcon::GOSSIP_ICON_TALK , "Corona de Hielo", GOSSIP_SENDER_MAIN, 28);
                    AddGossipItemFor(player, GossipOptionIcon::GOSSIP_ICON_TALK , "|CFF800080[Atras]|r", GOSSIP_SENDER_MAIN, 0);
                    SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                    break;

                case 5:// Teleport a Orgrimmar
                    player->TeleportTo(1 , 1481.3325f, -4416.5292f, 25.4622f, 0.1125f);
                    CloseGossipMenuFor(player);
                    break;

                case 6:// Teleport a Cima del Trueno
                    player->TeleportTo(1, -1283.92f, 144.90f, 129.92f, 4.79f);
                    CloseGossipMenuFor(player);
                    break;

                case 7:// Teleport a Entrañas
                    player->TeleportTo(0, 1560.55f, 238.77f, -43.10f, 0.26f);
                    CloseGossipMenuFor(player);
                    break;

                case 8:// Teleport a Lunargenta
                    player->TeleportTo(530, 9476.64f, -7279.74f, 14.25f, 6.10f);
                    CloseGossipMenuFor(player);
                    break;

                case 9:// Teleport a Ventormenta
                    player->TeleportTo(0, -9020.60f, 467.98f, 95.12f, 0.79f);
                    CloseGossipMenuFor(player);
                    break;

                case 10:// Teleport a Forjaz
                    player->TeleportTo(0, -4899.26f, -899.10f, 501.66f, 4.5f);
                    CloseGossipMenuFor(player);
                    break;

                case 11:// Teleport a Darnassus
                    player->TeleportTo(1, 9949.82f, 2350.78f, 1330.74f, 1.49f);
                    CloseGossipMenuFor(player);
                    break;

                case 12:// Teleport a El Exodar
                    player->TeleportTo(530, -3831.19f, -11705.91f, -106.72f, 2.52f);
                    CloseGossipMenuFor(player);
                    break;

                case 13:// Teleport a Península del Fuego Infernal
                    player->TeleportTo(530, -273.23f, 2866.17f, -5010.0f, 1.568f);
                    CloseGossipMenuFor(player);
                    break;

                case 14:// Teleport a Marisma de Zangar
                    player->TeleportTo(530, 214.889f, 7085.96f, 35.22f, 6.24f);
                    CloseGossipMenuFor(player);
                    break;

                case 15:// Teleport a Nagrand
                    player->TeleportTo(530, -1689.98f, 7562.80f, -2.477f, 0.955f);
                    CloseGossipMenuFor(player);
                    break;

                case 16:// Teleport a Montañas Filospada
                    player->TeleportTo(530, 2797.824f, 6056.928f, -10.23f, 3.954f);
                    CloseGossipMenuFor(player);
                    break;

                case 17:// Teleport a Tormenta Abisal
                    player->TeleportTo(530, 3451.418f, 2919.847f, 144.12f, 5.259f);
                    CloseGossipMenuFor(player);
                    break;

                case 18:// Teleport a Bosque de Terokkar
                    player->TeleportTo(530, -2412.438f, 4623.03f, 160.67f, 1.94f);
                    CloseGossipMenuFor(player);
                    break;

                case 19:// Teleport a Valle Sombraluna
                    player->TeleportTo(530, -3513.993f, 1867.33f, 86.95f, 5.45f);
                    CloseGossipMenuFor(player);
                    break;

                case 20:// Teleport a Dalaran
                    player->TeleportTo(571, 5826.125f, 471.9993f, 658.78f, 1.42f);
                    CloseGossipMenuFor(player);
                    break;

                case 21:// Teleport a Cementerio de Dragones
                    player->TeleportTo(571, 3893.006f, 374.146f, 41.18f, 3.764f);
                    CloseGossipMenuFor(player);
                    break;

                case 22:// Teleport a Fiordo Aquilonal
                    player->TeleportTo(571, 1311.173f, -4573.29f, 183.946f, 4.042f);
                    CloseGossipMenuFor(player);
                    break;

                case 23:// Teleport a Tundra Boreal
                    player->TeleportTo(571, 3339.9562f, 5224.827f, 26.077f, 2.532f);
                    CloseGossipMenuFor(player);
                    break;

                case 24:// Teleport a Cuenca de Sholazar
                    player->TeleportTo(571, 5508.21679f, 4985.1118f, -129.9162f, 4.567f);
                    CloseGossipMenuFor(player);
                    break;

                case 25:// Teleport a Colinas Pardas
                    player->TeleportTo(571, 3841.881f, -3454.691f, 288.75f, 3.598f);
                    CloseGossipMenuFor(player);
                    break;

                case 26:// Teleport a Zul'drak
                    player->TeleportTo(571, 5571.582f, -3216.6999f, 372.38f, 5.43f);
                    CloseGossipMenuFor(player);
                    break;

                case 27:// Teleport a Cumbres Tormentosas
                    player->TeleportTo(571, 7350.731f, -1003.186f, 908.539f, 4.434f);
                    CloseGossipMenuFor(player);
                    break;

                case 28:// Teleport a Corona de Hielo
                    player->TeleportTo(571, 6902.9624f, 2017.8796f, 922.028f, 3.295f);
                    CloseGossipMenuFor(player);
                    break;

                case 99:// Cerrar el menu
                    ClearGossipMenuFor(player);
                    OnGossipHello(player); 
                    break;
            }
            return true;
        }
    };
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new teletransportScriptAI(creature);
    }
};

void AddSC_teletransportScript()
{
    new teletransportScript();
};
