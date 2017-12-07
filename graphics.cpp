
#include <math.h>
#include "graphics.h"
device::device(){
int display_count = 0, display_index=0, mode_index = 0;
SDL_DisplayMode mode1={SDL_PIXELFORMAT_UNKNOWN, 0, 0, 0, 0};
if ((display_count = SDL_GetNumVideoDisplays()) < 1) {  }
if (SDL_GetDisplayMode (display_index, mode_index, &mode1) != 0) {  }
w=mode1.w;
h=mode1.h;
m=SDL_BITSPERPIXEL(mode1.format);
}
int device::height(){return h;
}
int device::width(){return w;
}
int device::mode(){
return m;
}



image::image(SDL_Renderer* r ){
		ren=r;
	}
image::~image(){
	
		ren=NULL;
}
void image::point(int x,int y  ){
		
			SDL_RenderDrawPoint( ren, x , y );
	}
	void image::color(int r,int g,int b,int a){
	 SDL_SetRenderDrawColor( ren, r, g, b, a );
}
void image::line(int x,int y,int x1,int y1){
	
		SDL_RenderDrawLine( ren, x, y, x1, y1);
}
	 void image::clear( ){
	 
	
	 	SDL_RenderClear(ren);	 
}
		

	void image::rectangle(SDL_Rect rect,int para){if (para==0)
	 SDL_RenderFillRect( ren, &rect);
	 else SDL_RenderDrawRect( ren, &rect );
}
void image::redraw(){
	 SDL_RenderPresent( ren);
}
void image::texture( SDL_Texture* tex){
	SDL_RenderCopy( ren, tex, NULL, NULL );
	};

void image::circle( int x,int y,int r ){
/*
  int x,y;
   x = radius;y = 0;
   int xChange = 1 - (radius << 1);
  int yChange = 0;
   int radiusError = 0;
  while (x >= y){
  for (int i=x0 - x;i<x0 + x;i++){
    point(i, y0 + y);
    point(i, y0 - y);
    
   }
  for (int i=x0 - y;i<x0 + y;i++){
    point(i, y0 + x);
    point(i, y0 - x);
    
   }
   y++;
   radiusError += yChange;
   yChange += 2;
   if (((radiusError << 1) + xChange) > 0){
    x-=1;
      radiusError += xChange;
      xChange += 2; }   
    }
*/

int x1;
int x2;
int counter=(y+r);

for ( int count=(y-r);count<=counter;count++)
{
x1= (x+sqrt((r*r)-((count-y)*(count-y)))+0.5);
x2=(x-sqrt((r*r)-((count-y)*(count-y)))+0.5);
line(x1,count,x2,count);
}

}
tool::tool(){}
bool tool::init(   SDL_Window* win  ){
		if(ren = SDL_CreateRenderer( win, -1, SDL_RENDERER_ACCELERATED )) return true;
	else if (ren = SDL_CreateRenderer( win, -1, SDL_RENDERER_SOFTWARE )) return true;
	else return false;
	}

tool::~tool(){
		SDL_DestroyRenderer( ren);
		ren=NULL;
}
texture::texture(SDL_Texture  * texa){
	tex=texa;
	
}
texture::~texture(){
		SDL_DestroyTexture( tex );
	tex=NULL;
}

SDL_Surface * tool::loadbmp(const char * path){
	 SDL_Surface* file  = SDL_LoadBMP( path);
 return file;
	
}
SDL_Texture*  tool::loadpng(const char * path){
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path);
	if( loadedSurface == NULL )
	{
	 IMG_GetError() ;
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( ren, loadedSurface );
		if( newTexture == NULL )
		{
		 SDL_GetError() ;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

window * create_w(  int h,int w,const char *s  ){
	window* win;
		bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		"SDL could not initialize! SDL_Errorn" ;SDL_GetError();
		success = false;
		
	}
	
	else{
	win = SDL_CreateWindow( s, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN );
		if( win == NULL )
		{
		//	print "Window could not be created! SDL Error: %s\n"<<SDL_GetError() ;
			success = false;
		}
		else{
			 
			
				//Initialize renderer color
				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
			//		print "SDL_image could not initialize! SDL_image Error:"<< IMG_GetError() ;
					success = false;
}
			}}
return win;
	
}

void close_w(window* &win){
	SDL_DestroyWindow( win);
win = NULL;
SDL_Quit();IMG_Quit();}
