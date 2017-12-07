#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
typedef SDL_Window window;
class device{
private:
int w,h,m;
public:
device();
int height();
int width();
int mode();
}
;
class image{
	enum fill_type{
		fill,nofill
	};
	SDL_Renderer  * ren=NULL;
	public:
	image(SDL_Renderer* r );
	void point(int x,int y);
	void rectangle(SDL_Rect rect,int para=0);
	void color(int r,int g,int b,int a);
	void line(int x,int y,int x1,int y1);
	void clear();
void texture( SDL_Texture* tex);
	void redraw();
~image();
void circle(int x0,int y0,int radius);
};
class tool{
public:
	 SDL_Renderer* ren=NULL;
	
tool();
bool init(    SDL_Window* win   );

~tool();
 SDL_Surface  * loadbmp(const char* path);
  
SDL_Texture  * loadpng(const char* path);
};
class texture{
public:
SDL_Texture  * tex=NULL;
texture( SDL_Texture  * texa);
~texture();
};
 void close_w(window *&win);
window * create_w( int h,int w,const char* s="" );
//#include "graphics.cpp"
#endif

