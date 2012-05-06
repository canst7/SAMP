forward OnMessageShown(playerID, messageID);
public OnMessageShown(playerID, messageID)
{
	switch (messageID)
	{
		case 1:
		{
			ShowMessage(playerID, 2, 3000);
		}
		case 2:
		{
			ShowMessage(playerID, 3, 3000);
		}
		case 3:
		{
			ShowMessage(playerID, 4, 3000);
		}
		case 4:
		{
			ShowMessage(playerID, 5, 3000);
		}
		case 5:
		{
			StartScreenFader(playerID, 0, 0, 0, 5, 0, FADE_TUTORIAL_S1_END_BLACK);
		}
		case 6:
		{
			//InterpolateCameraToPos(playerID, 1082.5531, 1068.0121, 10.8359, 2000, CAMERA_MOVE);
			//InterpolateCameraToLookAt(playerID, 1046.4423, 1021.8431, 33.3791, 2000, CAMERA_MOVE);
			ShowMessage(playerID, 7, 6000);
		}
		case 7:
		{
			InterpolateCameraToPos(playerID, 1043.6639, 1015.4567, 12.9713, 2000, CAMERA_MOVE);
			InterpolateCameraToLookAt(playerID, 1045.3195, 1010.8120, 11.0000, 2000, CAMERA_MOVE);
			ShowMessage(playerID, 8, 5000);
		}
		case 8:
		{
			StartScreenFader(playerID, 0, 0, 0, 5, 0, FADE_TUTORIAL_BANK_END_BLACK);
		}
	}
}