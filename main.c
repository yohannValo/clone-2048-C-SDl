#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int comptezero (int **tableau) // cette fonction permet de compter le nombre de case vide dans le tableau
//elle sert a savoir si l'on tire un un nombre au hasard ou non
{
    int i, j,compteur;
    compteur=0;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(tableau[j][i]!=0)
            {
                compteur++;// augmentation par un compteur a chaque fois que l'on tombe sur un 0
            }
        }
    }
    return compteur;// on retourne cette valeur
}

int possibleDown(int** tableau) // c'est à peur près la meme fonction que la fonction possibleleft regarder la fonction pour comprendre
{
    int tableau2[4];
    int possible[4]= {1};
    int i,j,k,m;
    int compteur = 0;
    k=0;

    for(i=3; i>=0; i--)
    {
        for(j=3; j>=0; j--)
        {
            if (tableau[i][j]==0)
            {
                tableau2[j]=0;
            }
            else tableau2[j]=1;
        }
        possible[i]=tableau2[0]*1000+tableau2[1]*100+tableau2[2]*10+tableau2[3];
        if(possible[i]==1||possible[i]==11||possible[i]==111||possible[i]==1111)
        {
            for(m=3; m>=1; m--)
            {
                if(tableau[i][m]==tableau[i][m-1]&&tableau[i][m]!=0) //effectue le calcul de la multiplication par deux des cases collées egales et met la suivante a 0
                {
                    k++;
                }
            }
            if(k!=0)
            {
                possible[i]=1;
            }
            else
                possible[i]=0;
        }
        else if (possible[i]==0000)
        {
            possible[i]=0;
        }
        else possible[i]=1;
    }
    for(i=0; i<4; i++)
    {
        if(possible[i]==0)
        {
            compteur++;
        }
    }
    return compteur;
}

void down(int** tableau)// cette fonction est quasiment identique a left la logique reste la même
{
    int i,j,o,p,compteur;
    int tableauTemp[4][4]= {0};
    int tableauTemp2[4][4]= {0};

    for(i=3; i>=0; i--)
    {
        compteur=3;
        for(j=3; j>=0; j--)
        {
            if(tableau[i][j]!=0)
            {
                tableauTemp[i][compteur]=tableau[i][j];
                compteur--;
            }
        }
    }

    for(i=3; i>=0; i--)
    {
        for(j=3; j>=1; j--)
        {
            if(tableauTemp[i][j]==tableauTemp[i][j-1]) //effectue le calcul de la multiplication par deux des cases collées egales et met la suivante a 0
            {
                tableauTemp[i][j]=2*tableauTemp[i][j];
                tableauTemp[i][j-1]=0;
            }
        }
    }

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            tableauTemp2[j][i]=tableauTemp[j][i];
        }
    }

    for(i=3; i>=0; i--)
    {
        compteur=3;
        for(j=3; j>=0; j--)
        {
            if(tableauTemp[i][j]!=0)
            {
                tableauTemp2[i][compteur]=tableauTemp[i][j];
                tableauTemp2[i][compteur-1]=0;
                compteur--;
            }
        }
    }
    for(o=0; o<4; o++)
    {
        for(p=0; p<4; p++)
        {
            tableau[p][o]= tableauTemp2[p][o];
        }
    }
}

int possibleUp(int** tableau) // c'est à peur près la meme fonction que la fonction possibleleft regarder la fonction pour comprendre
{
    int tableau2[4];
    int possible[4]= {1};
    int i,j,k,m;
    int compteur = 0;
    k=0;

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if (tableau[i][j]==0)
            {
                tableau2[j]=0;
            }
            else tableau2[j]=1;
        }
        possible[i]=tableau2[0]*1000+tableau2[1]*100+tableau2[2]*10+tableau2[3];
        if(possible[i]==1000||possible[i]==1100||possible[i]==1110||possible[i]==1111)
        {
            for(m=0; m<3; m++)
            {
                if(tableau[i][m]==tableau[i][m+1]&&tableau[i][m]!=0) //effectue le calcul de la multiplication par deux des cases collées egales et met la suivante a 0
                {
                    k++;
                }

            }
            if(k!=0)
            {
                possible[i]=1;
            }
            else
                possible[i]=0;

        }
        else if (possible[i]==0000)
        {
            possible[i]=0;
        }
        else possible[i]=1;
    }
    for(i=0; i<4; i++)
    {
        if(possible[i]==0)
        {
            compteur++;
        }
    }
    return compteur;
}

void up(int** tableau)// cette fonction est quasiment identique a left la logique reste la même
{
    int i,j,o,p,compteur;
    int tableauTemp[4][4]= {0};
    int tableauTemp2[4][4]= {0};

    for(i=0; i<4; i++)
    {
        compteur=0;
        for(j=0; j<4; j++)
        {
            if(tableau[i][j]!=0)
            {
                tableauTemp[i][compteur]=tableau[i][j];
                compteur++;

            }

        }

    }

    for(i=0; i<4; i++)
    {
        for(j=0; j<3; j++)
        {
            if(tableauTemp[i][j]==tableauTemp[i][j+1]) //effectue le calcul de la multiplication par deux des cases collées egales et met la suivante a 0
            {
                tableauTemp[i][j]=2*tableauTemp[i][j];
                tableauTemp[i][j+1]=0;
            }
        }
    }

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            tableauTemp2[j][i]=tableauTemp[j][i];

        }

    }

    for(i=0; i<4; i++)
    {
        compteur=0;
        for(j=0; j<4; j++)
        {
            if(tableauTemp[i][j]!=0)
            {
                tableauTemp2[i][compteur]=tableauTemp[i][j];
                tableauTemp2[i][compteur+1]=0;
                compteur++;

            }

        }

    }
    for(o=0; o<4; o++)
    {
        for(p=0; p<4; p++)
        {
            tableau[p][o]= tableauTemp2[p][o];
        }
    }

}

int possibleRight(int ** tableau)  // c'est à peur près la meme fonction que la fonction possibleleft regarder la fonction pour comprendre
{
    int tableau2[4];
    int possible[4]= {1};
    int i,j,k,m;
    int compteur = 0;
    k=0;

    for(i=3; i>=0; i--)
    {
        for(j=3; j>=0; j--)
        {
            if (tableau[j][i]==0)
            {
                tableau2[j]=0;
            }
            else tableau2[j]=1;
        }
        possible[i]=tableau2[0]*1000+tableau2[1]*100+tableau2[2]*10+tableau2[3];
        if(possible[i]==1||possible[i]==11||possible[i]==111||possible[i]==1111)
        {
            for(m=3; m>=1; m--)
            {
                if(tableau[m][i]==tableau[m-1][i]&&tableau[m][i]!=0) //effectue le calcul de la multiplication par deux des cases collées egales et met la suivante a 0
                {
                    k++;
                }

            }
            if(k!=0)
            {
                possible[i]=1;
            }
            else
                possible[i]=0;

        }
        else if (possible[i]==0000)
        {
            possible[i]=0;
        }
        else possible[i]=1;
    }
    for(i=0; i<4; i++)
    {
        if(possible[i]==0)
        {
            compteur++;
        }
    }
    return compteur;

}

void right(int **tableau)// cette fonction est quasiment identique a left la logique reste la même
{
    int i,j,o,p,compteur;
    int tableauTemp[4][4]= {0};
    int tableauTemp2[4][4]= {0};

    for(i=3; i>=0; i--)
    {
        compteur=3;
        for(j=3; j>=0; j--)
        {
            if(tableau[j][i]!=0)
            {
                tableauTemp[compteur][i]=tableau[j][i];
                compteur--;

            }

        }

    }
    for(i=3; i>=0; i--)
    {
        for(j=3; j>=1; j--)
        {
            if(tableauTemp[j][i]==tableauTemp[j-1][i]) //effectue le calcul de la multiplication par deux des cases collées egales et met la suivante a 0
            {
                tableauTemp[j][i]=2*tableauTemp[j][i];
                tableauTemp[j-1][i]=0;
            }
        }
    }

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            tableauTemp2[i][j]=tableauTemp[i][j];

        }

    }
    for(i=3; i>=0; i--)
    {
        compteur=3;
        for(j=3; j>=0; j--)
        {
            if(tableauTemp[j][i]!=0)
            {
                tableauTemp2[compteur][i]=tableauTemp[j][i];
                tableauTemp2[compteur-1][i]=0;
                compteur--;

            }

        }

    }
    for(o=0; o<4; o++)
    {
        for(p=0; p<4; p++)
        {
            tableau[p][o]= tableauTemp2[p][o];
        }
    }

}

int possibleLeft(int ** tableau) //Cette fonction permet de savoir si il y a un mouvement de chiffre possible dans le tableau
{
    int tableau2[4];//déclaration de mes variables
    int possible[4]= {1};
    int i,j,k,m;
    int compteur = 0;
    k=0;

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if (tableau[j][i]==0)
            {
                tableau2[j]=0;// on parcours la i eme ligne du tableau et si il y a un 0 donc une case vide on rentre un 0 dasn tableau 2 sinon on rentre un 1
            }
            else tableau2[j]=1;
        }
        possible[i]=tableau2[0]*1000+tableau2[1]*100+tableau2[2]*10+tableau2[3];//dans possible i on rentre le nombre formé des 4 cases tu tableau2
        if(possible[i]==1000||possible[i]==1100||possible[i]==1110||possible[i]==1111)// si ce nombre correspond a un des 4 cas montré on effectue les actions suivantes
        {
            for(m=0; m<3; m++)
            {
                if(tableau[m][i]==tableau[m+1][i]&&tableau[m][i]!=0) // si une case est egale a sa suivante et qu'elle est non vide alors on incrémente un compteur k
                {
                    k++;
                }

            }
            if(k!=0)
            {
                possible[i]=1;// si k est non nul on rentre 1 dans possible [i]
            }
            else
                possible[i]=0;//sinon 0

        }
        else if (possible[i]==0000)//si possible [i] =0000 on met un 0 dasn possible [i] sinon un 1
        {
            possible[i]=0;
        }
        else possible[i]=1;
    }
    for(i=0; i<4; i++)
    {
        if(possible[i]==0) //Apres avoir fait varier i de 0 a 3 on se retrouve donc avec possible qui est un tableau de 4 case complété avec soit des 0 soit des 1
        // dans le cas ou on a un 0 on augmente le compteur
        {
            compteur++;
        }
    }
    return compteur;// on retourne le compteur il nous permettra de détermineer si un mouvement est possible
}

void left(int **tableau)// cette fonction nous permet de décaler les cases à gauche lorsque le joueur presse la flèche gauche
{
    int i,j,o,p,compteur;
    int tableauTemp[4][4]= {0};// on créer deux tableau temporaire initialisés à 0
    int tableauTemp2[4][4]= {0};

    for(i=0; i<4; i++)
    {
        compteur=0;
        for(j=0; j<4; j++)
        {
            if(tableau[j][i]!=0)
            {
                tableauTemp[compteur][i]=tableau[j][i];// ce premier double for permet de rentrer dasn tableau temporaire la valeur de tableau si celle si egale 0
                //cela permet ainsi de pouvoir avoir un tableau ou on a des chiffres puis des 0
                compteur++;// ce compteur permet de placer les nombres aux bonnen places dans le tableau temporaire

            }

        }

    }

    for(i=0; i<4; i++)
    {
        for(j=0; j<3; j++)
        {
            if(tableauTemp[j][i]==tableauTemp[j+1][i]) //effectue le calcul de la multiplication par deux des cases collées egales et met la suivante a 0
            {
                tableauTemp[j][i]=2*tableauTemp[j][i];
                tableauTemp[j+1][i]=0;
            }
        }
    }

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            tableauTemp2[j][i]=tableauTemp[j][i];// recopiage de tableau temp dans tableau temp2

        }

    }

    for(i=0; i<4; i++)
    {
        compteur=0;
        for(j=0; j<4; j++)
        {
            if(tableauTemp[j][i]!=0)
            {
                tableauTemp2[compteur][i]=tableauTemp[j][i];// ce double for permet de tout redécaler sur la gauche en décalant le nombre et mettant la case suivante a 0
                tableauTemp2[compteur+1][i]=0;
                compteur++;

            }

        }

    }


    for(o=0; o<4; o++)
    {
        for(p=0; p<4; p++)
        {
            tableau[p][o]= tableauTemp2[p][o];// on copie le tableau temp 2 dans le tableau passé en paramètre
        }
    }

}

void aleatoire(int ** tableau)//cette fonction permet d'ajouter aléatoirement un nombre soit 2 soit 4 dans le tableau dans une case vide  au hasard
{
    srand(time(NULL));
    int val_randi;
    int val_randj;//permet de selectionner une case du tableau
    int val_rand2;//permet d effectuer un pourcentage
    do
    {
        val_randi=rand()%4;// permet de tire run nombre entre 0 et 3
        val_randj=rand()%4;
    }
    while(tableau[val_randi][val_randj]!=0);// tant que la case en i et j est non nul on continue de tirer de nouveaux i et j
    val_rand2=rand()%5;// on tire un nombre entre 0 et 4
    switch(val_rand2)
    {
    case 0 :
        tableau[val_randi][val_randj]=4;    /*il y a 2 chances sur 5 qu'un quatre soit tiré au hasard et 3 chances sur 5 que ca soit un 2*/
        break;
    case 1 :
        tableau[val_randi][val_randj]=2;
        break;
    case 2 :
        tableau[val_randi][val_randj]=2;
        break;
    case 3 :
        tableau[val_randi][val_randj]=2;
        break;
    case 4 :
        tableau[val_randi][val_randj]=4;
        break;
    default:
        break;
    }
}

void afficher_nombre(SDL_Window*window,SDL_Renderer*renderer,SDL_Rect pos, int** tableau)// cette fonction permet d'afficher le jeu a chaque action du joueur
{

    SDL_Color couleur= {0,0,0};// on déclare les textures les surfaces la police et les couleurs
    int i,j,largeur,hauteur;
    TTF_Font* police;
    police = TTF_OpenFont("arial.ttf",45);
    char buffer[5];
    SDL_Texture* texture=NULL;
    SDL_Surface* numero=NULL;
    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );

    // on vide le rendu
    SDL_RenderClear( renderer );

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            pos.x =i*(148+15) ; //creer les rectangles pour former la grille
            pos.y = j*(148+15);
            pos.h=154;
            pos.w= 154;
            SDL_SetRenderDrawColor( renderer, 248,230, 223, 255 );

            SDL_RenderFillRect( renderer, &pos );
            //on rempli les rectangles
        }
    }

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            couleur.r=0;
            couleur.g=0;
            couleur.b=0;

            if (tableau[i][j]!=0)// on regarde le nombre a afficher dans chaque case et selon ce nombre on lui attribue une couleur
            {
                sprintf(buffer, "%d",tableau[i][j]);
                switch (tableau[i][j])
                {
                case 2:
                    couleur.r = 255;
                    break;
                case 4:
                    couleur.b=255;
                    break;
                case 8:
                    couleur.g =255;
                    break;
                case 16:
                    couleur.r=255;
                    couleur.g=120;
                    break;
                case 32:
                    couleur.g=130;
                    couleur.b=100;
                    break;
                case 64:
                    couleur.r=40;
                    couleur.g=60;
                    couleur.b=251;
                    break;
                case 128:
                    couleur.r=70;
                    couleur.g=80;
                    couleur.b=251;
                    break;
                case 256:
                    couleur.r=40;
                    couleur.g=100;
                    couleur.b=15;
                    break;
                case 512:
                    couleur.r=200;
                    couleur.g=60;
                    couleur.b=21;
                    break;
                case 1024:
                    couleur.r=90;
                    couleur.g=120;
                    couleur.b=47;
                    break;
                case 2048:
                    couleur.r=40;
                    couleur.g=200;
                    couleur.b=81;
                    break;
                case 4096:
                    couleur.r=150;
                    couleur.g=100;
                    couleur.b=31;
                    break;
                }
                numero = TTF_RenderText_Solid(police, buffer, couleur); // on initialise le texte
                largeur = numero->w;
                hauteur = numero->h;
                pos.x = i*(148+15)+ (163/2 - largeur/2);// on defini la position du nombre dans la case pour qu'il soit centré en x
                pos.y = j*(148+15)+ (163/2 - hauteur/2);//on defini la position du nombre dans la case pour qu'il soit centré en y
                pos.h = 0;
                pos.w = 0;
                texture = SDL_CreateTextureFromSurface(renderer,numero);/* ENfin on affiche le texte */
                SDL_QueryTexture(texture,NULL,NULL,&pos.w,&pos.h);
                SDL_FreeSurface(numero);
                SDL_RenderCopy(renderer,texture,NULL,&pos);
                SDL_DestroyTexture(texture);
                SDL_SetRenderDrawColor(renderer,100,0,0, 255);
            }

        }
    }
    SDL_RenderPresent(renderer);// on actualise le rendu

}

int main(int argc, char* argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO) == -1)//initialisation de la vidéo en cas d'erreur on la retourne
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    if(TTF_Init() == -1)//initialisation de l'utilisation du texte en cas d'erreur on la retourne
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    if(IMG_Init(IMG_INIT_PNG) == -1)//initialisation de l'utilisation des images en cas d'erreur on la retourne
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }
    srand(time(NULL));//on initialise le temps
    int ** tableau;//tableau contenant les 16 cases du jeu
    SDL_Event e; //déclaration d'un évenement
    int i,j,k,l;
    k=1;
    l=1;
    TTF_Font* police;//déclaration d'une police de texte
    TTF_Font* police2048;
    police = TTF_OpenFont("arial.ttf",29);// on choisi la police
    police2048 = TTF_OpenFont("arial.ttf",100);
    SDL_Texture* texture2=NULL;//on definit une texture
    SDL_Surface* texte=NULL;//on defini une surface
    SDL_Texture* texture2048=NULL;
    SDL_Surface* texte2048=NULL;
    SDL_Color couleur= {0,0,0,255};
    SDL_Color couleur2048= {255,0,0,255};
    SDL_Window* window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 640, SDL_WINDOW_SHOWN);//on créer une fenetre
    SDL_Renderer* renderer = SDL_CreateRenderer(window,-1, SDL_RENDERER_ACCELERATED);// on créer un rendu
    SDL_Event continu;
    SDL_Rect pos;
    SDL_Rect postexte;

    while(l!=0)
    {
        while(SDL_PollEvent(&continu))// ce premier while permet de créer l'écran d'accueil
        {
            SDL_Surface *image = IMG_Load("2048accueil.png");// on charge l'image de fond
            pos.x = 0;
            pos.y = 0;
            pos.w = image->w;
            pos.h = image->h;
            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer,image);// on créer une texture à partir d'une surface
            SDL_RenderCopy(renderer,texture,NULL,&pos);// on copie cette texture sur le renderer

            texte2048= TTF_RenderText_Solid(police2048, "2048", couleur2048);// meme chose qu'au dessus mais avec du texte
            texture2048 = SDL_CreateTextureFromSurface(renderer,texte2048);
            postexte.x=210;
            postexte.y=180;
            postexte.h=50;
            postexte.w=50;
            SDL_QueryTexture(texture2048,NULL,NULL,&postexte.w,&postexte.h);
            SDL_RenderCopy(renderer,texture2048,NULL,&postexte);

            texte= TTF_RenderText_Solid(police, "appuyer sur une touche pour commencer à jouer", couleur);//texte aussi
            texture2 = SDL_CreateTextureFromSurface(renderer,texte);
            postexte.x=10;
            postexte.y=300;
            postexte.h=50;
            postexte.w=50;
            SDL_QueryTexture(texture2,NULL,NULL,&postexte.w,&postexte.h);
            SDL_RenderCopy(renderer,texture2,NULL,&postexte);

            SDL_RenderPresent(renderer);// On actualise le renderer pour afficher le rendu
            SDL_DestroyTexture(texture);//on détruit la texture pour récuperer de la mémoire
            SDL_FreeSurface(image);//de meme avec la mémoire
            switch(continu.type)
            {
            case SDL_QUIT ://le cas ou on quitte la fenetre on change une variable
                l=0;
                break;

            case SDL_KEYDOWN : //dans le cas ou une touche est pressé le jeu démarre
                tableau = malloc(4*sizeof(int*));// création d'un tableau de 4 par 4 avec une allocation dynamique afin de pouvoir passer le tableau en paramètre
                for(i=0; i<4; i++)
                {
                    tableau[i]= malloc(4*sizeof(int));
                    for(j=0; j<4; j++)
                    {
                        tableau[i][j]=0; // on initialise le tableau à 0
                    }
                }
                aleatoire(tableau); // on insere un nombre aléatoire dans le tableau un 2 ou un 4
                afficher_nombre(window,renderer,pos,tableau); // on affiche le jeu
                while(k!=0)
                {
                    while(SDL_WaitEvent(&e))// on attend un événement
                    {
                        switch(e.type)
                        {

                        case SDL_QUIT :
                            k=0;
                            break;

                        case SDL_KEYDOWN :
                            switch(e.key.keysym.sym)
                            {
                            case SDLK_LEFT: // si le joueur presse la tocuhe gauche
                                if(possibleLeft(tableau)!=4)// on executela suite des instructions si et seulement si il est possible déplacer les nombres sur la gauche
                                {
                                    left(tableau);// on déplace les nopmbres
                                    afficher_nombre(window,renderer,pos,tableau);//on affiche le jeu
                                    if(comptezero(tableau)!=0)
                                    {
                                        aleatoire(tableau);// si il reste de la place pour afficher un nombre aléatoire on l'affiche
                                    }
                                    afficher_nombre(window,renderer,pos,tableau);
                                }
                                break;

                            case SDLK_RIGHT://de meme pour la droite
                                if(possibleRight(tableau)!=4)
                                {
                                    right(tableau);
                                    afficher_nombre(window,renderer,pos,tableau);
                                    if(comptezero(tableau)!=0)
                                    {
                                        aleatoire(tableau);
                                    }
                                    afficher_nombre(window,renderer,pos,tableau);
                                }
                                break;

                            case SDLK_UP:// de meme por le haut
                                if(possibleUp(tableau)!=4)
                                {
                                    up(tableau);
                                    afficher_nombre(window,renderer,pos,tableau);
                                    if(comptezero(tableau)!=0)
                                    {
                                        aleatoire(tableau);
                                    }
                                    afficher_nombre(window,renderer,pos,tableau);
                                }
                                break;

                            case SDLK_DOWN:// de meme pour le bas
                                if(possibleDown(tableau)!=4)
                                {
                                    down(tableau);
                                    afficher_nombre(window,renderer,pos,tableau);
                                    if(comptezero(tableau)!=0)
                                    {
                                        aleatoire(tableau);
                                    }
                                    afficher_nombre(window,renderer,pos,tableau);
                                }
                                break;

                            default :
                            {}
                            }

                            break;

                        default:
                        {}
                        }
                    }
                }
                break;


            default:
            {}
            }
        }

    }
    SDL_DestroyRenderer(renderer);// on détruit le rendu
    SDL_DestroyWindow(window);// on détruit la fenetre
    IMG_Quit();//on quitte l image le texte et la sdl
    TTF_Quit();
    SDL_Quit();

    return 0;// on retourne  si tout s'est bien passé
}

