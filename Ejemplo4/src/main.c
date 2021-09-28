#include <genesis.h>
#include <resources.h>

const short nivel1_map[14][40] = {
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0 },
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1 },
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1 }
};


//Declarar las orillas de la pantalla
const int ORILLA_IZQ = 0;
const int ORILLA_DER = 640;//320
const int ORILLA_ARR = 0;
const int ORILLA_ABJ = 224;

const int MITAD_1RA_PANT = 160;
const int MITAD_ULTIMA_PANT = 640 - 160;

const int pl_altura = 16;
const int pl_anchura = 16;

const int gravedad = 1;

Sprite* jugador;
int plx=16;
int ply=16;
int showx,movx,movy;
const int max_movy=5;

bool saltando = FALSE;
bool en_piso = FALSE;

Map *bga, *bgb;
u16 ind, bgBaseTileIndex[2];

void prepararControles(u16 control,u16 suelto, u16 boton)
{
    if (control == JOY_1)
	{
		if (boton & BUTTON_RIGHT)
		{
			movx=3;
			SPR_setAnim(jugador,1);
            SPR_setHFlip(jugador, FALSE);
		}
		else if (boton & BUTTON_LEFT)
		{
			movx=-3;
			SPR_setAnim(jugador,1);
            SPR_setHFlip(jugador, TRUE);
		}
        else if( (suelto & BUTTON_RIGHT) | (suelto & BUTTON_LEFT) )
        {
            movx = 0;
            SPR_setAnim(jugador,0);
		}

        if (boton & BUTTON_C)
        {
            if(saltando == FALSE && en_piso)
            {
                saltando = TRUE;
                movy=-13;
            }
        } else if (suelto & BUTTON_C) saltando = FALSE;
	}
}

void moverJugador()
{
    if (movy>max_movy) movy=max_movy;
    plx+=movx;
    ply+=movy;

    movy+=gravedad;

    /*Mantener al personaje dentro de la pantalla*/
	if(plx < ORILLA_IZQ) plx = ORILLA_IZQ;
	if(plx + pl_anchura > ORILLA_DER) plx = ORILLA_DER - pl_anchura;

    if (nivel1_map[(ply>>4)+2][plx>>4]==1 || nivel1_map[(ply>>4)+2][(plx>>4)+1]==1)
    {
        ply=(ply>>4)<<4;
        en_piso = TRUE;
    } else en_piso=FALSE;

    if (nivel1_map[ply>>4][(plx>>4)+1]==1) plx=(plx>>4)<<4;
    if (nivel1_map[ply>>4][(plx>>4)]==1) plx=((plx>>4)+1)<<4;

    SPR_setPosition(jugador,showx-8,ply);
}

void desplazarPantalla()
{
   if (plx>=MITAD_1RA_PANT && plx <=MITAD_ULTIMA_PANT)
    {
        showx=160;
        MAP_scrollTo(bga, plx-160, 0);
        MAP_scrollTo(bgb, (plx-160)/2, 0);
    }
    else if (plx >MITAD_ULTIMA_PANT)
        showx=plx+160+(pl_anchura*2);
    else showx=plx;
}

int main(u16 hard)
{
    JOY_init();
    JOY_setEventHandler( &prepararControles );

    ind = TILE_USERINDEX;
    bgBaseTileIndex[0] = ind;
    VDP_loadTileSet(&bga_tileset, ind, DMA);
    ind += bga_tileset.numTile;
    bgBaseTileIndex[1] = ind;
    VDP_loadTileSet(&bgb_tileset, ind, DMA);
    ind += bgb_tileset.numTile;

    VDP_setPalette(PAL0, background1.palette->data);
    VDP_setPalette(PAL0, background2.palette->data);

    VDP_drawText("HOLA MUNDO",1,1);
    VDP_setPaletteColor(PAL0,RGB24_TO_VDPCOLOR(0x6dc2ca));
    VDP_setPalette(PAL1, sprJugador.palette->data);

    SPR_init();
    jugador = SPR_addSprite(&sprJugador,plx-8,ply,TILE_ATTR(PAL1,0, FALSE, FALSE));

    bga = MAP_create(&bga_map, BG_A, TILE_ATTR_FULL(0, FALSE, FALSE, FALSE, bgBaseTileIndex[0]));
    bgb = MAP_create(&bgb_map, BG_B, TILE_ATTR_FULL(0, FALSE, FALSE, FALSE, bgBaseTileIndex[1]));

    MAP_scrollTo(bga, 0, 0);
    MAP_scrollTo(bgb, 0, 0);

    while (1)
    {
        moverJugador();
        desplazarPantalla();

        SPR_update();
        SYS_doVBlankProcess();
    }

    MEM_free(bga);
    MEM_free(bgb);

    return 0;
}
