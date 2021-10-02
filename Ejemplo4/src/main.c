#include <genesis.h>
#include <resources.h>

//Datos del nivel en cuadricula de 16x16 pixeles
//1=Bloque solido   0=Nada
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

//Constantes para revisar si el personaje avanza hasta la mitad de la pantalla
const int MITAD_1RA_PANT = 160;
const int MITAD_ULTIMA_PANT = 640 - 160;

//Dimensiones del personaje
const int pl_altura = 16;
const int pl_anchura = 16;

const int gravedad = 1;

//Mas variables para el personaje
Sprite* jugador;
int plx=16;
int ply=16;
int showx,movx,movy;
const int max_movy=5;

bool saltando = FALSE;
bool en_piso = FALSE;

//Fondos
Map *bga, *bgb;
u16 ind, bgBaseTileIndex[2];

//Controlar al personaje
void prepararControles(u16 control,u16 suelto, u16 boton)
{
    if (control == JOY_1)
	{
		if (boton & BUTTON_RIGHT)//Derecha
		{
			movx=3;
			SPR_setAnim(jugador,1);
            		SPR_setHFlip(jugador, FALSE);//Voltear
		}
		else if (boton & BUTTON_LEFT)//Izquierda
		{
			movx=-3;
			SPR_setAnim(jugador,1);
            		SPR_setHFlip(jugador, TRUE);//Voltear
		}
		else if( (suelto & BUTTON_RIGHT) | (suelto & BUTTON_LEFT) )//Si ninguno de los dos es pulsado entonces que se detenga
		{
		    movx = 0;
		    SPR_setAnim(jugador,0);
		}

		if (boton & BUTTON_C)//Si el boton C es pulsado
		{
		    if(saltando == FALSE && en_piso)
		    {
			saltando = TRUE;//Indicar que ya esta saltando
			movy=-13;//Hacia arriba
		    }
		} else if (suelto & BUTTON_C) saltando = FALSE;
	}
}

//Actualizar las ubicaciones del jugador
void moverJugador()
{
    if (movy>max_movy) movy=max_movy;//Que no caiga tan rapido
    plx+=movx;
    ply+=movy;

    movy+=gravedad;

    /*Mantener al personaje dentro de la pantalla*/
	if(plx < ORILLA_IZQ) plx = ORILLA_IZQ;
	if(plx + pl_anchura > ORILLA_DER) plx = ORILLA_DER - pl_anchura;

	//Colisiones
	//Pisando el suelo?
    if (nivel1_map[(ply>>4)+2][plx>>4]==1 || nivel1_map[(ply>>4)+2][(plx>>4)+1]==1)
    {
        ply=(ply>>4)<<4;
        en_piso = TRUE;
    } else en_piso=FALSE;

	//Chocando contra las paredes?
    if (nivel1_map[ply>>4][(plx>>4)+1]==1) plx=(plx>>4)<<4;
    if (nivel1_map[ply>>4][(plx>>4)]==1) plx=((plx>>4)+1)<<4;

    SPR_setPosition(jugador,showx-8,ply);//Visualizar en pantalla con las posiciones indicadas
}

//Si el jugador avanza y ya va a la mitad de la pantalla
void desplazarPantalla()
{
   if (plx>=MITAD_1RA_PANT && plx <=MITAD_ULTIMA_PANT)
    {
        showx=160;
        MAP_scrollTo(bga, plx-160, 0);//Mover primer fondo
        MAP_scrollTo(bgb, (plx-160)/2, 0);//Mover el fondo de mero atras (segundo)
    }
    else if (plx >MITAD_ULTIMA_PANT)
        showx=plx+160+(pl_anchura*2);//Si va al final del nivel, que ya se mueva hasta el tope de la pantalla
    else showx=plx;
}

//Cuerpo principal del programa
int main(u16 hard)
{
    JOY_init();//Iniciar controles
    JOY_setEventHandler( &prepararControles );//Llamar al procedimiento de preparar controles

    ind = TILE_USERINDEX;//Cargar los fondos
    bgBaseTileIndex[0] = ind;
    VDP_loadTileSet(&bga_tileset, ind, DMA);//Primero
    ind += bga_tileset.numTile;
    bgBaseTileIndex[1] = ind;
    VDP_loadTileSet(&bgb_tileset, ind, DMA);//Segundo
    ind += bgb_tileset.numTile;

    VDP_setPalette(PAL0, background1.palette->data);//Colorear primer fondo
    VDP_setPalette(PAL0, background2.palette->data);//Colorear segundo fondo

    VDP_drawText("HOLA MUNDO",1,1);//Escribir texto en las posiciones indicadas
    VDP_setPaletteColor(PAL0,RGB24_TO_VDPCOLOR(0x6dc2ca));//Cargar color de fondo
    VDP_setPalette(PAL1, sprJugador.palette->data);

    SPR_init();//Iniciar sprite del personaje
    jugador = SPR_addSprite(&sprJugador,plx-8,ply,TILE_ATTR(PAL1,0, FALSE, FALSE));//Agregar sprite del personaje

    bga = MAP_create(&bga_map, BG_A, TILE_ATTR_FULL(0, FALSE, FALSE, FALSE, bgBaseTileIndex[0]));//Agregar primer fondo
    bgb = MAP_create(&bgb_map, BG_B, TILE_ATTR_FULL(0, FALSE, FALSE, FALSE, bgBaseTileIndex[1]));//Agregar segundo fondo

    MAP_scrollTo(bga, 0, 0);//Colocar primer fondo en las posiciones indicadas
    MAP_scrollTo(bgb, 0, 0);//Colocar segundo fondo en las posiciones indicadas

    //Esto ya es lo que se va a ejecutar todo el tiempo
    while (1)
    {
	//Llamar a los procediientos
        moverJugador();
        desplazarPantalla();

        SPR_update();
        SYS_doVBlankProcess();//Limpiar graficos no necesarios para el siguiente fotograma
    }

    MEM_free(bga);
    MEM_free(bgb);

    return 0;
}
