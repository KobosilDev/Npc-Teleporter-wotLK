# Npc-Teleporter-wotLK
Npc Teleporter en c++ para Wrath of the Lich King (wotLK) 3.3.5

# Añadir el script en  ...script/Custom/

# Añadir una nueva linea en ...script/Custom/custom_script_loader.cpp


void AddSC_teletransportScript();

void AddCustomScripts()
{

        AddSC_teletransportScript();
}

# Usa CMAKE y luego compile el proyecto

# Asigne el script a una criatura en la base de datos y añada el npc en el juego.
