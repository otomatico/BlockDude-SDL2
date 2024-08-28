#define CONFIG_SIZE (255)

#ifdef _DEBUG_
void dumpTile(Tile *this)
{
	SDL_Log("{\n width:%d,\n height:%d,\n map:[", this->width, this->height);
	int max = this->width * this->height;
	for (int count = 0; count < max - 1; count++)
	{
		if (count % this->width == 0)
		{
			SDL_Log("\n\t");
		}
		SDL_Log("%d, ", this->map[count]);
	}
	SDL_Log("%d\n     ]\n}\n", this->map[max - 1]);
}
#endif
int parse_Tile(TileList *this, char *filename)
{
	typedef enum
	{
		NUMBER_LEVEL,
		SIZE_LEVEL,
		TILE_MAP,
		END
	} EnumReadMap;

	char buffer[CONFIG_SIZE];
	char dummy[CONFIG_SIZE];
	int line_number , num , countLevel , countTile;
	line_number = num = countLevel = countTile = 0;
	Tile *currentMap = NULL;
	FILE *file;
	EnumReadMap state = NUMBER_LEVEL;
	file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("Not able to open the file.");
		return -1;
	}

	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		++line_number;  //printf("%01d:  %s", line_number, buffer);
		if (sscanf(buffer, " %s", dummy) == EOF) continue; // blank line
		if (sscanf(buffer, " %[#]", dummy) == 1) continue; // comment

		switch (state)
		{
		case NUMBER_LEVEL:
			if (sscanf(buffer, "%u", &num) == 1)
			{
				countLevel = 0;
				this->lenght = num;
				this->Map = newArray(Tile, num);
				state = SIZE_LEVEL;
			}
			break;
		case SIZE_LEVEL:
			currentMap = &this->Map[countLevel];
			if (sscanf(buffer, "%d %d", &(currentMap->width), &(currentMap->height)) == 2)
			{
				countTile = 0;
				int size = currentMap->width * currentMap->height;
				currentMap->map = newArray(Uint8, size);
				state = TILE_MAP;
			}
			break;
		case TILE_MAP:
			if (sscanf(buffer, "%s", dummy) == 1)
			{
				int index = countTile * currentMap->width;
				for (int count = 0; dummy[count] != '\0'; count++)
				{
					currentMap->map[index + count] = dummy[count] - '0';
				}
				countTile++;
				if (countTile >= currentMap->height)
				{
					countLevel++;
					state = (countLevel < num) ? SIZE_LEVEL : END;
				}
			}
			break;
		default:
			break;
		}
	}
	fclose(file);
	return num;
}

int loadLevel(Tile *this, int level)
{
	static TileList MasterMap;
	if (MasterMap.lenght == 0)
	{
		parse_Tile(&MasterMap, PATH_MAP);
	}
	if (level < MasterMap.lenght)
	{
		Tile *current = &MasterMap.Map[level];
		int size = current->width * current->height;
		this->width = current->width;
		this->height = current->height;
		this->map = newArray(Uint8, size);
		memcpy(this->map, current->map, size);
	}
	return MasterMap.lenght;
}

void drawTile(Tile *this)
{
	int index, row, col;
	for (row = 0; row < this->height; row++)
	{
		index = row * this->width;
		for (col = 0; col < this->width; col++)
		{
			spr(this->map[index + col], col * 8, row * 8, 1, 1);
		}
	}
}

int getElement(Tile *this, Point2D position)
{
	int index = this->width * position.y + position.x;
	return this->map[index];
}
