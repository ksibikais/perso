#include"fenetre.h"
int main() {


//------------------------------------------declaration
SDL_Surface* screen ; 
struct_img background;
int quitter;
SDL_Event event;
Personne p;
 
uint32_t tprev;
Uint32 t_prev;
int posinit;
 
float dt;
int numperso;
 
int choix;
//------------------------------------------declaration

 






//------------------------------------------initlisation
choix=0;
SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO);
screen= SDL_SetVideoMode(600, 600, 32, SDL_RESIZABLE|SDL_HWSURFACE);
quitter=1;
numperso=1;
 
init_image2(&background);
//initPerso(&p);
 
init(&p,numperso);
posinit=555;
 
//------------------------------------------initlisation 

 
 
 
 
 
  
//------------------------------------------boucle jeux
  
while(quitter){
t_prev=SDL_GetTicks();	//au début de la boucle de jeu
//------------------display
SDL_BlitSurface(background.image,NULL,screen,NULL);
afficherPerso(p,screen);
 
//------------------display

//------------------lecture input
SDL_PollEvent(&event);

switch(event.type){
  
  case SDL_QUIT:
  quitter=0;
  break;
  
  
//------------------keyenzel 3la button mel clavier
  case SDL_KEYDOWN:
switch(event.key.keysym.sym) {
  case SDLK_c:
  p.perso.image=IMG_Load("resources/images/sprite sheet/sprite2.png");
  break;
case SDLK_DOWN:
break;
case SDLK_UP:
if(choix==0){
if(p.up==0){
p.up=1;
    p.velocityX=0;
    p.velocityY=-80; }}
break;
case SDLK_RIGHT:
if(choix==0){
p.deplacement=1;
p.direction=0;}
break;
case SDLK_LEFT:
if(choix==0){
p.deplacement=1;
p.direction=1;}
break;
case SDLK_o:
if(choix==1){
if(p.up==0){
p.up=1;
    p.velocityX=0;
    p.velocityY=-80; }}
break;
case SDLK_m:
if(choix==1){
p.deplacement=1;
p.direction=0;}
break;
case SDLK_k:
if(choix==1){
p.deplacement=1;
p.direction=1;}
break;

case SDLK_a: 
p.etatA=1;
break;
case SDLK_d: 
p.etatD=1;
break;
case SDLK_SPACE:
if(p.up==0){
p.up=1;
    p.velocityX=40;
    p.velocityY=-80; }
break;

 
}
break;
//------------------keyenzel 3la button mel clavier


//------------------ke yrelachi button
  case SDL_KEYUP:
switch(event.key.keysym.sym) {
case SDLK_DOWN:
break;
case SDLK_UP:
break;
case SDLK_a: 
p.etatA=0;
break;
case SDLK_d: 
p.etatD=0;
break;
case SDLK_SPACE:
break;
case SDLK_RIGHT:
if(choix==0) {
p.deplacement=0;}
break;
case SDLK_LEFT:
if(choix==0) {
p.deplacement=0;}
break;
case SDLK_m:
if(choix==1){
p.deplacement=0;}
break;
case SDLK_k:
if(choix==1){
p.deplacement=0;}
break;


 
}
break;
//------------------ke yrelachi button

}

//------------------lecture input


//------------------update
p.acceleration-=0.001; //à chaque itération et sans événement préalable
if(p.etatA==1){p.acceleration+=0.005;}
else if(p.etatD==1){p.acceleration-=0.01;}

if(p.acceleration<0){
 p.acceleration=0; 
}
if(p.acceleration>0.2) {
 p.acceleration=0.2; 
}
if(p.deplacement==1){
  p.Vscore+=1;
  p.vitesse=0.5;
p.acceleration+=0.002;

}else if(p.deplacement==0){
   p.vitesse=0; 
}
if(p.up==0 ){
movePerso(&p);
}
if(p.deplacement==1||p.up==1) {
    if(SDL_GetTicks()-tprev>80) {
animerPerso(&p);
tprev=SDL_GetTicks();
  }
}
 saut(&p,dt,posinit); 

//-------------------------------2eme joeur
 

//------------------update 
printf("%f\n", p.acceleration);
SDL_Flip(screen);
p.dt=SDL_GetTicks()-t_prev;	//à la fin de la boucle de jeu
 
dt=(SDL_GetTicks()-t_prev)/100.0;
}

//------------------------------------------boucle jeux






//------------------------------------------liberation
SDL_FreeSurface(background.image);
SDL_Quit();
//------------------------------------------liberation





}

