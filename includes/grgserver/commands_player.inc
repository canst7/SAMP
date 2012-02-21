CMD:about(playerid, params[])
{
	SendClientMessage(playerid, COLOR_INFO, "Created by Aerox_Tobi (aerox@grgserver.net) and Programie (programie@selfcoders.com)");
	return COMMAND_OK;
}

CMD:cmds(playerid, params[])
{
	if (fexist("commands.txt"))
	{
		new string[256];
		new line[256];
		new count;
		new File:commands = fopen("commands.txt", io_read);
		while (fread(commands, string))
		{
			new type;
			new command[256];
			new permission[256];
			RemoveNewLine(string);
			if (sscanf(string, "css", type, command, permission))
			{
				sscanf(string, "cs", type, command);
			}
			if (type)
			{
				new showCommand;
				if (type == 'P')
				{
					showCommand = true;
					format(command, sizeof(command), "{00FF00}%s", command);
				}
				if (type == 'A' && strlen(permission))
				{
					print("Is Admin CMD");
					new permissionID = GetPermissionByName(permission);
					if (permissionID != -1)
					{
						if (permissions[playerid][enum_permission:permissionID])
						{
							showCommand = true;
							format(command, sizeof(command), "{A00000}%s", command);
						}
					}
				}
				if (showCommand)
				{
					count++;
					if (count == 1)
					{
						format(line, sizeof(line), "/%s", command);
					}
					else
					{
						format(line, sizeof(line), "%s /%s", line, command);
					}
					if (count == HELP_COMMANDSPERLINE)
					{
						count = 0;
						SendClientMessage(playerid, COLOR_INFO, line);
					}
				}
			}
		}
		if (!count)
		{
			SendClientMessage(playerid, COLOR_INFO, line);
		}
		return COMMAND_OK;
	}
	else
	{
		return COMMAND_ERROR;
	}
}

CMD:exit(playerid, params[])
{
	if (GetPVarType(playerid, "ShowInterior_OldInterior") == PLAYER_VARTYPE_NONE)
	{
		if (LeaveBuilding(playerid))
		{
			return COMMAND_OK;
		}
		else
		{
			SendClientMessage(playerid, COLOR_ERROR, "Du bist in keinem Haus!");
			return COMMAND_ERROR;
		}
	}
	else
	{
		SetPlayerPos(playerid, GetPVarFloat(playerid, "ShowInterior_OldPosX"), GetPVarFloat(playerid, "ShowInterior_OldPosY"), GetPVarFloat(playerid, "ShowInterior_OldPosZ"));
		SetPlayerInterior(playerid, GetPVarInt(playerid, "ShowInterior_OldInterior"));
		DeletePVar(playerid, "ShowInterior_OldPosX");
		DeletePVar(playerid, "ShowInterior_OldPosY");
		DeletePVar(playerid, "ShowInterior_OldPosZ");
		DeletePVar(playerid, "ShowInterior_OldInterior");
		return COMMAND_OK;
	}
}

CMD:help(playerid, params[])
{
	SendClientMessage(playerid, COLOR_INFO, "Verwende /cmds um eine Liste an Befehlen zu sehen.");
	return COMMAND_OK;
}

CMD:me(playerid, params[])
{
	if (strlen(params))
	{
		new string[256];
		format(string, sizeof(string), "*%s %s", GetPlayerNameEx(playerid), params);
		SendClientMessageToAll(COLOR_ME, string);
		return COMMAND_OK;
	}
	else
	{
		CmdUsageMsg(playerid, "me", "Text");
		return COMMAND_USAGE;
	}
}

CMD:motor(playerid, params[])
{
	if (!IsPlayerInAnyVehicle(playerid))
	{
		return COMMAND_NOT_IN_VEHICLE;
	}
	if (GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
	{
		SendClientMessage(playerid, COLOR_ERROR, "Du bist nicht der Fahrer dieses Fahrzeugs!");
		return COMMAND_ERROR;
	}
	new vehicleID = GetPlayerVehicleID(playerid);
	if (GetVehicleEngineState(vehicleID))
	{
		SetVehicleEngineState(vehicleID, false);
		SendClientMessage(playerid, COLOR_INFO, "Der Motor deines Fahrzeuges wurde ausgeschalten.");
	}
	else
	{
		new Float:health;
		GetVehicleHealth(vehicleID, health);
		if (health < VEHICLE_MINHEALTH)
		{
			SendClientMessage(playerid, COLOR_ERROR, "Der Motor deines Fahrzeuges konnte nicht gestartet werden (Motorschaden)!");
		}
		else
		{
			SetVehicleEngineState(vehicleID, true);
			SendClientMessage(playerid, COLOR_INFO, "Der Motor deines Fahrzeuges wurde gestartet.");
		}
	}
	return COMMAND_OK;
}

CMD:ordervehicle(playerid, params[])
{
	new JobID = GetPVarInt(playerid, "JobID");
	if (JobID == JOB_VEHICLEDEALER)
	{
		ShowDialog(playerid, DIALOG_ORDERVEHICLE);
	}
	else
	{
		return COMMAND_PERMISSION_DENIED;
	}
	return COMMAND_OK;
}

CMD:radio(playerid, params[])
{
	if (IsPlayerInAnyVehicle(playerid))
	{
		ShowDialog(playerid, DIALOG_RADIO);
		return COMMAND_OK;
	}
	else
	{
		return COMMAND_NOT_IN_VEHICLE;
	}
}