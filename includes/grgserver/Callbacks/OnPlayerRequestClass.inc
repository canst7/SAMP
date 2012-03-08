public OnPlayerRequestClass(playerid, classid)
{
	new previousClassID = GetPVar:playerid[PREVIOUSCLASSID];
	new direction;
	switch (classid)
	{
		case 0:
		{
			switch (previousClassID)
			{
				case 1:
					direction--;
				case 2:
					direction++;
			}
		}
		case 1:
		{
			switch (previousClassID)
			{
				case 2:
					direction--;
				case 0:
					direction++;
			}
		}
		case 2:
		{
			switch (previousClassID)
			{
				case 0:
					direction--;
				case 1:
					direction++;
			}
		}
	}
	SetPVar:playerid[PREVIOUSCLASSID](classid);
	new skinID = GetPVar:playerid[SKIN];
	switch (direction)
	{
		case -1:
		{
			do
			{
				skinID--;
				if (skinID < 0)
				{
					skinID = 298;
				}
			}
			while (!IsValidSkin(skinID));
		}
		case 1:
		{
			do
			{
				skinID++;
				if (skinID > 298)
				{
					skinID = 0;
				}
			}
			while (!IsValidSkin(skinID));
		}
	}
	SetPVar:playerid[SKIN](skinID);
	SetPlayerSkin(playerid, skinID);
	SetPlayerPos(playerid, SPAWN_POSX, SPAWN_POSY, SPAWN_POSZ);
	SetPlayerFacingAngle(playerid, SPAWN_ANGLE);
	SetPlayerCameraPos(playerid, SPAWN_CAMERAPOSX, SPAWN_CAMERAPOSY, SPAWN_CAMERAPOSZ);
	SetPlayerCameraLookAt(playerid, SPAWN_POSX, SPAWN_POSY, SPAWN_POSZ);
	return true;
}