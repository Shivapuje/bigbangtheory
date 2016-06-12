#include <GL/globals.h>
#include <GL/glut.h>
#include <GL/solarsys.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

void main3();

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f }; 
 
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f }; 

//GLenum spinMode = GL_TRUE;
  //        GLenum singleStep = GL_FALSE;


int f=1;

const float DEG2RAD = 3.14159/180;
float ct = 0.5;
GLfloat b = 0;
GLfloat red = 0.0, green = 0.749, blue = 1.0;
GLfloat red2 = 0.0, green2 = 0.933, blue2 = 0.0 ;

GLfloat p=-3.0, t=-2.0, q=-1.3, r=3.0, s=0.0, xvel=0.03;
int refmil = 20, window, window3;

void *fonts[]= {
	GLUT_BITMAP_9_BY_15,
	GLUT_BITMAP_TIMES_ROMAN_10,
	GLUT_BITMAP_TIMES_ROMAN_24,
	GLUT_BITMAP_HELVETICA_18,
	GLUT_BITMAP_HELVETICA_12
};

class bigbang
{
      private:
		  GLfloat offset1, res;
	  public:
		  bigbang()
		  {
		  offset1=0, res=0;
		  }
		  


		  void init()
		  {
                glClearColor(0.0,0.0,0.0,0.0);
                glColor3f(1.0,0,0);
                glPointSize(3.0);
                glLineWidth(3.0);
                glMatrixMode(GL_PROJECTION);
                glLoadIdentity();
                gluOrtho2D(0,1000,0,700);

		  }





void DrawCircle(float cx, float cy, float r, int num_segments)
 {
                glBegin(GL_POLYGON);
                for (int ii = 0; ii < num_segments; ii++)
                {
					glColor3f(0.9,0.9,0.9);
					//glColor3f(1.0+(float)ii,0.8,0.6);
                                float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
                                float x = r * cosf(theta);//calculate the x component ,to find the cartesian co-ordinate
                                float y = r * sinf(theta);//calculate the y component
                                glVertex2f(x + cx, y + cy);//output vertex
                }
                glEnd();
}


void drawParticle(float x, float y,float r,float density)
{
	DrawCircle(x,y,r,density);
}




void output(int x, int y, char *string,void *font)
{
	int len, i;

	glRasterPos2f(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++)
		glutBitmapCharacter(font, string[i]);
}


void introduction()
{

	int pos=80;

	glColor3f(0,1,1);
	output(400, 600-pos, "What is the Big Bang?",fonts[2]);
	glColor3f(1,1,1);
	output(345, 540-pos, "The universe, as we know it, was created",fonts[2]);
	output(345,515-pos,"as a result of the Big Bang. It is a theory",fonts[2]);
	output(345,490-pos,"about how the universe started with a small",fonts[2]);
    output(345,465-pos,"singularity and expanded over the next",fonts[2]);
	output(345,440-pos,"13 billion years. It all started as a result",fonts[2]);
	output(345,415-pos,"of the collision of particles.",fonts[2]);

	glColor3f(0.752,0.752,0.752);
	output(400,350-pos,"Press '1' to view the collision",fonts[3]);
}



void animate_particles()
{
	 if(offset1<400)
	  offset1+=0.2;
     	 if(offset1==400)
		 res=1;
  
  glPushMatrix();
  glTranslatef(offset1,0,0);
  drawParticle(100.0,200.0,25.0,50);
  glPopMatrix();

  glColor3f(1.0,0.8,0);
  glPushMatrix();
  glTranslatef(-offset1,0,0);
  drawParticle(900.0,200.0,25.0,50);
  glPopMatrix();

}




void display(void)
{
	
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
    init();
    introduction();
	animate_particles();
  glutPostRedisplay();
  glFlush();

}

	static void resizeWindow(int w, int h)
		{
		    float aspectRatio;
			h = (h == 0) ? 1 : h;
			w = (w == 0) ? 1 : w;
			glViewport( 0, 0, w, h );	// View port uses whole window
			aspectRatio = (float)w/(float)h;

			// Set up the projection view matrix (not very well!)
			glMatrixMode( GL_PROJECTION );
			glLoadIdentity();
		    gluPerspective( 60.0, aspectRatio, 1.0, 30.0 );
	
			// Select the Modelview matrix
			glMatrixMode( GL_MODELVIEW );
		}

}bigbang;



class pangaea
{

	public:
	pangaea(void)
	{
		b=0;
	}

	void output(int x, int y, char *string,void *font)
{
	int len, i;

	glRasterPos2f(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++)
		glutBitmapCharacter(font, string[i]);
}

	void introduction()
{

	int pos=80;

	glColor3f(0,1,1);
	output(450, 600-pos, "Pangaea",fonts[2]);
	glColor3f(1,1,1);
	output(315, 540-pos, "The 7 continents we know today have existed",fonts[2]);
	output(315,515-pos,"for a long time, but not in their current positions",fonts[2]);
	output(315,490-pos,"since the beginning. Pangaea was a supercontinent",fonts[2]);
    output(315,465-pos,"that existed 250 million years ago, until it broke off",fonts[2]);
	output(315,440-pos,"and separated into 7 continents as a result of disturbances ",fonts[2]);
	output(315,415-pos,"in the Earth's tectonic plates, caused by natural calamities",fonts[2]);
	output(315,390-pos,"such as volcanic eruptions and earthquakes.",fonts[2]);

	glColor3f(0.752,0.752,0.752);
	output(340,330-pos,"Press '4' to illustrate the separation of Pangaea",fonts[3]);
}

	void continent_1()  //Top right
	{
		glLineWidth(5.0);
		glBegin(GL_POLYGON);
			glColor3f(0.0,0.3 ,0.02);
				glVertex2f(470,485);
				glVertex2f(485,500);
				glVertex2f(600,450);
				glVertex2f(635,415);
				glVertex2f(640,390);
				glColor3f(red2, green2, blue2);
				glVertex2f(610,370);
				glVertex2f(595,355);
				glVertex2f(560,345);	
				glVertex2f(495,440);
				glColor3f(0.0,0.3 ,0.02);
				glVertex2f(470,485);
		glEnd();

	}
 
	void continent_2()	//Bottom
	{
      glColor3f(red2, green2, blue2);
		glLineWidth(5.0);
		glBegin(GL_POLYGON);
				glVertex2f(560,345);
				glVertex2f(595,355);
				glColor3f(0.0,0.3 ,0.02);
				glVertex2f(610,370);
				glVertex2f(640,390);
				glVertex2f(685,285);			
				glVertex2f(690,230);
				glVertex2f(560,175);
				glVertex2f(550,180); 
				glVertex2f(540,192);
				glVertex2f(500,196);
				glVertex2f(480,200);
				glVertex2f(460,210);
				glVertex2f(400,200);
				glVertex2f(425,230);
				glVertex2f(435,255);
				glVertex2f(410,260);
				glVertex2f(390,275);
				glVertex2f(395,280);
				glVertex2f(395,300);
				glVertex2f(400,315);
				glVertex2f(420,330);
				glVertex2f(570,350);
		glEnd();
}	

	void continent_3()		//Top left
	{
	glColor3f(red2,green2,blue2);
		glLineWidth(5.0);
		glBegin(GL_POLYGON);
 
				glVertex2f(420,320);
				glVertex2f(410,350);
				glVertex2f(380,360);
				glColor3f(0.2,0.02 ,0.0);
				glVertex2f(375,410);
				glVertex2f(390,420);
				glVertex2f(393,415);
				glVertex2f(400,418);
				glVertex2f(415,425);
				glVertex2f(425,435);
				glVertex2f(440,445);
				glVertex2f(455,455);
				glColor3f(0.0,0.3 ,0.02);
				glVertex2f(460,460);
				glColor3f(0.2,0.02 ,0.0);
				glVertex2f(470,485);
				glVertex2f(495,440);
				glVertex2f(560,345);
				glColor3f(red2,green2,blue2);
				glVertex2f(435,360);
		glEnd();
	}	

	void stars()
	{
		for(int q=0;q<50;q++)
		{
			glBegin(GL_POINTS);
			//glPointSize(1);
			glColor3f(1,1,1);
			int starx=rand()%1000;
			int stary=rand()%700;
			glVertex2d(starx,stary);
			glEnd();
		}
	}


	void animate(GLfloat p)
	{
		glPushMatrix();
		glTranslatef(p,p,0);
			continent_1();
		glPopMatrix();

		glPushMatrix();
        glTranslatef(0,-p,0);
		    continent_2();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-p,0,0);
			continent_3();
		glPopMatrix();

	}

	void myInit()
	{
		glClearColor(0.0,0.0,0.0,0.0);
		//glColor3f(1.0,1.0,1.0);
		glPointSize(3.0);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0,1000,0,700);
	}

	void display()
	{
		  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
          glMatrixMode(GL_MODELVIEW);
		  myInit();
		  //introduction();
		//glClearColor(0,0,0,1);
		r = 300; 
		stars();
	
		//Earth
	glColor3f(0.0,0.05,0.4); 
    glBegin(GL_POLYGON);

	float j=0.0;
    for(float i=0.0;i<=360;i++)
    {
		j=i/100;
		glColor3f(0.0,0.05,j); 
		float degInRad = i*DEG2RAD;
        glVertex2f(cos(degInRad)*r+500,sin(degInRad)*r+350);
    }
	glEnd();
	
		if(b < 90.0)
			b = b + 0.01;
	
		animate(b);
		glutPostRedisplay();
	}
	
	static void resizeWindow(int w, int h)
		{
		    float aspectRatio;
			h = (h == 0) ? 1 : h;
			w = (w == 0) ? 1 : w;
			glViewport( 0, 0, w, h );	// View port uses whole window
			aspectRatio = (float)w/(float)h;

			// Set up the projection view matrix (not very well!)
			glMatrixMode( GL_PROJECTION );
			glLoadIdentity();
		    gluPerspective( 60.0, aspectRatio, 1.0, 30.0 );
	
			// Select the Modelview matrix
			glMatrixMode( GL_MODELVIEW );
		}
}pangaea;



class volcano
{
	private:
		GLfloat offset1, offset2, offset3, offset4, offset5, offset6, offset7, offset8;
	
	public:
		volcano()
		{
			offset1 = 0;
			offset2 = 0;
			offset3 = 0;
			offset4 = 0;
			offset5 = 0;
			offset6 = 0;
			offset7 = 0;
			offset8 = 0;
		}

		void init()
		{
			glClearColor(0.0,0.0,0.0,0.0);
            glColor3f(1.0,0,0);
            glPointSize(3.0);
			glLineWidth(3.0);
		    glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
			glutReshapeFunc(resizeWindow);
            gluOrtho2D(0,1500,0,1200);
		}


	//Drawing circles
		void DrawCircle(float cx, float cy, float r, int num_segments) 
		{
	        glBegin(GL_POLYGON);
            for (int ii = 0; ii < num_segments; ii++)
            {
				float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle                
                float x = r * cosf(theta);//calculate the x component ,to find the cartesian co-ordinate                
                float y = r * sinf(theta);//calculate the y component              
                glVertex2f(x + cx, y + cy);//output vertex
            }
            glEnd();
		} 

			void output(int x, int y, char *string,void *font)
{
	int len, i;

	glRasterPos2f(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++)
		glutBitmapCharacter(font, string[i]);
}

	void introduction()
{

	int pos=80;

	glColor3f(0,1,1);
	output(420, 600-pos, "Natural Disasters",fonts[2]);
	glColor3f(1,1,1);
	output(330, 540-pos,"After the Earth was formed billions of years",fonts[2]);
	output(330,515-pos,"ago, several environmental catastrophes such as",fonts[2]);
	output(330,490-pos,"earthquakes and volcanic eruptions took place",fonts[2]);

	glColor3f(0.752,0.752,0.752);
	output(400,400-pos,"Press '3' to illustrate them.",fonts[3]);
}

		void mountaintop(int d2,int d3)
		{
			glBegin(GL_POLYGON);
			glColor3f(1.0,0.22,0.0);
				glVertex2f(450+d2,570+d3);//top of the mountain
				glVertex2f(440+d2,580+d3);
			glColor3f(1,0.647,0);
				glVertex2f(460+d2,600+d3);
				glVertex2f(470+d2,600+d3);
				glVertex2f(480+d2,600+d3);
				glVertex2f(490+d2,605+d3);	
				glVertex2f(500+d2,610+d3);
				glVertex2f(505+d2,604+d3);
				glVertex2f(510+d2,598+d3);
				glVertex2f(515+d2,590+d3);
				glVertex2f(520+d2,585+d3);
			glColor3f(1.0,0.22,0.0);
				glVertex2f(525+d2,580+d3);
				glVertex2f(528+d2,570+d3);
			glEnd();
		}
		
 
		void display(void)
		{
           
                glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

                init();
				
				//Sky
                glBegin(GL_POLYGON);
                                glColor3f(0.9,0.21,0.0);
                                glVertex2f(0,525);
								glColor3f(0.2,0.84,1.0);	//glColor3f(0.9,0.21,0.0);
                                glVertex2f(0,1200);
                                glVertex2f(1500,1200);
								glColor3f(0.9,0.21,0.0);
								glVertex2f(1500,525);
                glEnd();
				
				//Sun
                glBegin(GL_POLYGON);
                                glColor3f(1.0,0.0,0.01);
                                DrawCircle(870.0,660.0,50.0,100);
                glEnd();
                
                //Environment
                glBegin(GL_POLYGON);
				                glColor3f(0.4,0.2,0);
                                //glColor3f(0.0,0.128,0.128);
                                glVertex2f(0,0);
                                glVertex2f(0,650);
                                glVertex2f(1500,650);
								glColor3f(0.1,0.02,0.0);
                    glVertex2f(1500,0);
                
                glEnd();
                
				
				

				//Right Mountain Animation
					offset5+=10;
				if(offset5==20)
				{
					offset5=0;
				}
			    glPushMatrix();
				glTranslatef(offset5,0,0);                     
				mountain(880,100);
				glPopMatrix();

				//left Mountain Animation
				offset8+=10;
				if(offset8==20)
				{
					offset8=0;
				}
			    glPushMatrix();
				glTranslatef(offset4,0,0);                     
				mountain(-200,200);
				glPopMatrix();
				
				//Middle Mountain Animation
					offset4+=10;
				if(offset4==20)
				{
					offset4=0;
				}
			    glPushMatrix();
				glTranslatef(offset4,0,0);                     
				mountain(280,0);
				glPopMatrix();
				
				//middle cloud animation
				offset1+=0.5;
				if(offset1==450)
					offset1=0;												
                glPushMatrix();
				glTranslatef(0,offset1,0);
                clouds();
				glPopMatrix();

				//left Cloud animation
					offset2+=0.5;
				if(offset2==550)
					offset2=0;												
                glPushMatrix();
				glTranslatef(-offset2,offset2,0);
                cloud2();
				glPopMatrix();
				
				//right cloud animation
				offset3+=0.5;
				if(offset3==500)
					offset3=0;
				glPushMatrix();
				glTranslatef(offset3,offset3,0);
                cloud3();
				glPopMatrix();
				glFlush();
		}

	
		void mountain(int d2=0,int d3=0)
		{
			//int d2=280;
			glBegin(GL_POLYGON);
			glColor3f(0.3,0.01,0.0);
				glVertex2f(100+d2,100+d3);
				glVertex2f(130+d2,120+d3);
				glVertex2f(150+d2,130+d3);
				glVertex2f(180+d2,160+d3);
				glVertex2f(200+d2,190+d3);
				glVertex2f(210+d2,220+d3);
				glVertex2f(215+d2,250+d3);
				glVertex2f(230+d2,280+d3);
				glVertex2f(250+d2,300+d3);
				glVertex2f(260+d2,320+d3);
				glVertex2f(280+d2,360+d3);
				glVertex2f(290+d2,380+d3);
				glVertex2f(300+d2,400+d3);
				glVertex2f(320+d2,440+d3);
				glVertex2f(335+d2,450+d3);
				glVertex2f(350+d2,455+d3);
				glVertex2f(360+d2,460+d3);
				glVertex2f(370+d2,465+d3);
				glVertex2f(380+d2,468+d3);
				glVertex2f(390+d2,470+d3);//checkpoint
				glVertex2f(391+d2,474+d3);
				glVertex2f(392+d2,478+d3);
				glVertex2f(393+d2,480+d3);
				glVertex2f(394+d2,484+d3);
				glVertex2f(396+d2,488+d3);
				glVertex2f(397+d2,490+d3);
				glVertex2f(398+d2,493+d3);
				glVertex2f(399+d2,496+d3);
				glVertex2f(400+d2,500+d3);
				glVertex2f(410+d2,520+d3);
				glVertex2f(420+d2,540+d3);
				glVertex2f(430+d2,560+d3);
				glVertex2f(440+d2,580+d3);
				//checkpoint.Descendfromhere
				glColor3f(0.3,0.01,0.0);
					glVertex2f(528+d2,570+d3);
					glVertex2f(530+d2,560+d3);
					glVertex2f(540+d2,540+d3);
					glVertex2f(550+d2,520+d3);
					glVertex2f(560+d2,500+d3);
					glVertex2f(570+d2,480+d3);
glVertex2f(580+d2,460+d3);
glVertex2f(590+d2,440+d3);
glVertex2f(590+d2,420+d3);
glVertex2f(595+d2,410+d3);
glVertex2f(600+d2,400+d3);
glVertex2f(610+d2,390+d3);
glVertex2f(620+d2,370+d3);
glVertex2f(630+d2,350+d3);
glVertex2f(640+d2,330+d3);
glVertex2f(650+d2,310+d3);
glVertex2f(660+d2,290+d3);
glVertex2f(670+d2,270+d3);
glVertex2f(680+d2,250+d3);
glVertex2f(690+d2,230+d3);
glVertex2f(700+d2,235+d3);
glVertex2f(710+d2,240+d3);
glVertex2f(720+d2,235+d3);
glVertex2f(730+d2,230+d3);
glVertex2f(740+d2,230+d3);
glVertex2f(750+d2,230+d3);
glVertex2f(755+d2,225+d3);
glVertex2f(760+d2,220+d3);
glVertex2f(770+d2,200+d3);
glVertex2f(780+d2,180+d3);
glVertex2f(790+d2,175+d3);
glVertex2f(800+d2,165+d3);
glVertex2f(810+d2,160+d3);
glVertex2f(820+d2,150+d3);
glVertex2f(830+d2,130+d3);
glVertex2f(840+d2,120+d3);
glVertex2f(850+d2,110+d3);
glVertex2f(870+d2,105+d3);
glVertex2f(890+d2,100+d3);//endofdescent
glColor3f(0.4,0.2,0);
glVertex2f(800+d2,93+d3);
glVertex2f(700+d2,90+d3);//startofbase
glVertex2f(600+d2,85+d3);
glVertex2f(500+d2,90+d3);
glVertex2f(350+d2,95+d3);
glVertex2f(225+d2,80+d3);
glVertex2f(100+d2,100+d3);//endofbase*/
glEnd();
	lava();
	mountaintop(d2,d3);
}
		//End of mountains
	
		
	void clouds()
{
	int d2=280,d3=300;

	glColor3f(0.41176,0.41176,0.41176);
	DrawCircle(670.0+d2,790.0,15.0,50);//setonebegins
	DrawCircle(660.0+d2,880.0,10.0,100);//20
	DrawCircle(650.0+d2,880.0,22.0,100);//22
	DrawCircle(630.0+d2,860.0,10.0,100);	
	DrawCircle(620.0+d2,830.0,10.0,50);
	DrawCircle(580.0+d2,800.0,17.0,100);
	DrawCircle(580.0+d2,780.0,13.0,100);
	DrawCircle(580.0+d2,760.0,5.0,100);
	DrawCircle(600.0+d2,780.0,20.0,100);//30
	DrawCircle(620.0+d2,740.0,25.0,50);
	//45//setoneends--rightsideclouds

	DrawCircle(470.0+d2,690.0,8.0,50);
	DrawCircle(470.0+d2,700.0,12.0,50);//set2(middle--topanimation)
	DrawCircle(460.0+d2,715.0,14.0,100);//20
	DrawCircle(480.0+d2,715.0,14.0,120);//22
	DrawCircle(460.0+d2,725.0,16.0,100);
	DrawCircle(475.0+d2,725.0,16.0,50);
	DrawCircle(485.0+d2,725.0,16.0,10);
	DrawCircle(500.0+d2,750.0,19.0,100);
	DrawCircle(490.0+d2,750.0,19.0,100);
	DrawCircle(480.0+d2,750.0,19.0,120);
	DrawCircle(470.0+d2,750.0,20.0,100);//30
	DrawCircle(460.0+d2,750.0,25.0,50);//45//setoneends
	DrawCircle(445.0+d2,780.0,30.0,100);
	DrawCircle(450.0+d2,780.0,30.0,100);
	DrawCircle(470.0+d2,780.0,30.0,100);
	DrawCircle(490.0+d2,780.0,30.0,100);
	DrawCircle(510.0+d2,780.0,30.0,100);
	DrawCircle(530.0+d2,800.0,30.0,100);
	DrawCircle(510.0+d2,800.0,35.0,100);
	DrawCircle(490.0+d2,800.0,35.0,100);
	DrawCircle(470.0+d2,800.0,35.0,100);//set2ends

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(-offset1,0,0);
	glPopMatrix();

glutPostRedisplay();
//glutSwapBuffers();
}

void cloud2()
{
int d2=70,d3=180;
glColor3f(0.41176,0.41176,0.41176);
DrawCircle(450.0+d2,800.0-d3,35.0,100);
DrawCircle(430.0+d2,800.0-d3,35.0,100);
DrawCircle(410.0+d2,830.0-d3,38.0,100);
DrawCircle(440.0+d2,830.0-d3,38.0,100);
DrawCircle(470.0+d2,830.0-d3,38.0,100);
DrawCircle(500.0+d2,830.0-d3,38.0,100);
DrawCircle(530.0+d2,830.0-d3,18.0,100);
DrawCircle(550.0+d2,830.0-d3,28.0,100);
DrawCircle(530.0+d2,860.0-d3,30.0,100);
DrawCircle(480.0+d2,900.0-d3,26.0,100);
DrawCircle(490.0+d2,930.0-d3,19.0,100);
DrawCircle(410.0+d2,930.0-d3,29.0,100);
DrawCircle(320.0+d2,960.0-d3,33.0,100);
DrawCircle(310.0+d2,940.0-d3,45.0,100);
DrawCircle(360.0+d2,960.0-d3,50.0,100);
DrawCircle(610.0+d2,960.0-d3,30.0,100);
DrawCircle(410.0+d2,960.0-d3,40.0,100);
DrawCircle(510.0+d2,960.0-d3,50,100);
DrawCircle(560.0+d2,860.0-d3,20.0,100);

glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glPushMatrix();
glTranslatef(-offset2,offset2,0);
glPopMatrix();

glutPostRedisplay();
//glutSwapBuffers();

}

void lava()
{

	offset7+=10;
	if(offset7==10)
		offset7=0;
	//Volcano
int d4=15,d2=280;

glBegin(GL_POLYGON);
glColor3f(1,0.647,0);
glVertex2f(495+d2-d4,600);
glVertex2f(500+d2-d4,600);
glVertex2f(510+d2-d4,70);
glVertex2f(485+d2-d4,70);
glEnd();
}


void cloud3()
{

int d2=560,d3=180;

glColor3f(0.41176,0.41176,0.41176);
DrawCircle(450.0+d2,800.0,35.0,100);
DrawCircle(450.0+d2,800.0-d3,35.0,100);
DrawCircle(430.0+d2,800.0-d3,35.0,100);
DrawCircle(410.0+d2,830.0-d3,38.0,100);
DrawCircle(440.0+d2,830.0-d3,38.0,100);
DrawCircle(470.0+d2,830.0-d3,38.0,100);
DrawCircle(500.0+d2,830.0-d3,38.0,100);
DrawCircle(530.0+d2,830.0-d3,18.0,100);
DrawCircle(550.0+d2,830.0-d3,28.0,100);
DrawCircle(530.0+d2,860.0-d3,30.0,100);
DrawCircle(480.0+d2,900.0-d3,26.0,100);
DrawCircle(490.0+d2,930.0-d3,19.0,100);
DrawCircle(410.0+d2,930.0-d3,29.0,100);
DrawCircle(320.0+d2,960.0-d3,33.0,100);
DrawCircle(310.0+d2,940.0-d3,45.0,100);
DrawCircle(360.0+d2,960.0-d3,50.0,100);
DrawCircle(610.0+d2,960.0-d3,30.0,100);
DrawCircle(410.0+d2,960.0-d3,40.0,100);
DrawCircle(510.0+d2,960.0-d3,50,100);
DrawCircle(560.0+d2,860.0-d3,20.0,100);

glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glPushMatrix();
glTranslatef(-offset2,0,0);
glPopMatrix();

glutPostRedisplay();
//glutSwapBuffers();
}

	static void resizeWindow(int w, int h)
		{
		    float aspectRatio;
			h = (h == 0) ? 1 : h;
			w = (w == 0) ? 1 : w;
			glViewport( 0, 0, w, h );	// View port uses whole window
			aspectRatio = (float)w/(float)h;

			// Set up the projection view matrix (not very well!)
			glMatrixMode( GL_PROJECTION );
			glLoadIdentity();
		    gluPerspective( 60.0, aspectRatio, 1.0, 30.0 );
	
			// Select the Modelview matrix
			glMatrixMode( GL_MODELVIEW );
		}
}volcano;



class life
{
	private:
		GLfloat offset1, offset2;
	
	public:	
		life()
		{
			offset1 =0;
			offset2 =0;
		}
		
		void init()
		{
            glClearColor(0.0,0.0,0.0,0.0);
            glColor3f(1.0,0,0);
            glPointSize(3.0);
            glLineWidth(3.0);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
			gluOrtho2D(0,1500,0,1200);
		}

		//Drawing Circles
		void DrawCircle(float cx, float cy, float r, int num_segments) 
		{
			glBegin(GL_POLYGON);
			for (int ii = 0; ii < num_segments; ii++)
			{
				float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
				float x = r * cosf(theta);//calculate the x component ,to find the cartesian co-ordinate
				float y = r * sinf(theta);//calculate the y component
				glVertex2f(x + cx, y + cy);//output vertex
			}
		     glEnd();
		}

		void output(int x, int y, char *string,void *font)
{
	int len, i;

	glRasterPos2f(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++)
		glutBitmapCharacter(font, string[i]);
}


void introduction()
{

	int pos=80;

	glColor3f(0,1,1);
	output(415, 600-pos, "Life on our planet",fonts[2]);
	glColor3f(1,1,1);
	output(330, 540-pos,"After all the events that took place billions",fonts[2]);
	output(330,515-pos,"of years ago, Life, as we know it, had originated",fonts[2]);
	output(330,490-pos,"on Earth. It lead to centuries of evolution, and",fonts[2]);
    output(330,465-pos,"continues to evolve even today.",fonts[2]);
   
	glColor3f(0.752,0.752,0.752);
	output(360,400-pos,"Press '5' to illustrate the early stages of life.",fonts[3]);
}

		void personMoving()
		{
			glPushMatrix();
			glTranslatef(offset2,0,0);
				person(250.0,450.0);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-offset2,offset2,0);
				person(650.0,500.0);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(offset2,offset2,0);
				person(1050.0,490.0);
			glPopMatrix();
		}

		void fishMoving()
		{
			glPushMatrix();
			glTranslatef(-offset1,0.0,0.0);
				fish();
			glPopMatrix();
		}


		//mountains
		void mountains()
		{
			glBegin(GL_POLYGON);
			glColor3f(0.4,0.15,0.0);
			glVertex2f(0,850);
				glVertex2f(0,900);
				glColor3f(0.3,0.7,0.36);
				glVertex2f(100,1000);
				glVertex2f(200,950);
				glVertex2f(300,990);
				glVertex2f(440,1030);
				glColor3f(0.1,0.8,0.22);
				glVertex2f(500,990);
				glVertex2f(660,950);
				glVertex2f(770,980);
				glVertex2f(900,1020);
				glVertex2f(1020,940);			
				glVertex2f(1200,1050);
				glVertex2f(1300,1000);
				glColor3f(0.3,0.7,0.36);
				glVertex2f(1420,950);
				glVertex2f(1500,900);
				glColor3f(0.4,0.15,0.0);
				glVertex2f(1500,850);
			glEnd();
		}

		void water()
		{
			glBegin(GL_POLYGON);
			glColor3f(0.6,0.81,1.0);
				glVertex2f(0,0);
			glColor3f(0.0,0.18,0.9);
				glVertex2f(0,220);
				glVertex2f(50,250);
				glVertex2f(100,250);
				glVertex2f(166,265);
				glVertex2f(220,285);
				glVertex2f(350,255);
				glVertex2f(450,275);
				glVertex2f(500,250);
				glVertex2f(550,259);
				glVertex2f(700,290);
				glVertex2f(900,250);
				glVertex2f(1100,290);
				glVertex2f(1300,260);
				glVertex2f(1500,250);
			glColor3f(0.6,0.81,1.0);
				glVertex2f(1500,0);
			glEnd();
		}

		//Tree function
		void tree()
		{
			int d=20;
			glBegin(GL_POLYGON); //Tree root
			glColor3f(0.4,0.15,0.0);
				glVertex2f(40-d,120);
				glVertex2f(60-d,380);
				glVertex2f(70-d,690);
			glColor3f(0.1,0.01,0.0);
				glVertex2f(75-d,670);
				glVertex2f(80-d,380);
				glVertex2f(100-d,120);
			glEnd();

			glColor3f(0.35,1.0,0.1);
				DrawCircle(10,620,63.0,40);
				DrawCircle(100,610,64.0,50);
				DrawCircle(90,670,65.0,50);
				DrawCircle(10,690,66.0,50);
		}

		void person(float x,float y)
		{
			//head code
			glColor3f(0.0,0.0,0.0);
			glBegin(GL_POLYGON);
				glVertex2f(x-20,y+90);
				glVertex2f(x-20,y+110);
				glVertex2f(x-10,y+130);
				glVertex2f(x,y+135);
				glVertex2f(x+10,y+130);
				glVertex2f(x+20,y+110);
				glVertex2f(x+20,y+90);
				glVertex2f(x,y+75);
			glEnd();
	
			// face code
			glColor3f(0.0,0.0,0.0);
			glBegin(GL_LINES);
				glVertex2f(x-13,y+110);
				glVertex2f(x-7,y+110);
				glVertex2f(x+7,y+110);
				glVertex2f(x+13,y+110);
				glVertex2f(x,y+105);
				glVertex2f(x,y+95);
				glVertex2f(x-05,y+85);
				glVertex2f(x+05,y+85);	
			glEnd();
	
			glColor3f(0.0,0.0,0.0);
			glBegin(GL_POLYGON);
				glVertex2f(x-10,y+130);
				glVertex2f(x,y+135);
				glVertex2f(x+10,y+130);
				glVertex2f(x+15,y+120);
				glVertex2f(x+10,y+135);	
	
			//glColor3f(1.0,0.67,0.6); //facecode
			//	DrawCircle(x,y,10,10);	
	
			glColor3f(0.0,0.0,0.0);
				glVertex2f(x,y+125);
				glVertex2f(x-5,y+130);
				glVertex2f(x-10,y+120);
				glVertex2f(x-15,y+125);
				glVertex2f(x-15,y+130);
			glEnd();

			// shirt code 
			glColor3f(1.0,0.67,0.6);
			glBegin(GL_POLYGON);
				glVertex2f(x,y);
				glVertex2f(x-20,y);
				glVertex2f(x-20,y+70);
				glVertex2f(x-20,y+80);
				glVertex2f(x-15,y+80);
				glVertex2f(x,y+70);
				glVertex2f(x+15,y+80);
				glVertex2f(x+20,y+80);
				glVertex2f(x+20,y+70);
				glVertex2f(x+20,y);
				glVertex2f(x,y);
			glEnd();
	
			// shoulders and hands code
			glColor3f(1.0,0.67,0.6);
			glBegin(GL_POLYGON);
				glVertex2f(x-20,y+65);
				glVertex2f(x-20,y+80);
				glVertex2f(x-30,y+80);
				glVertex2f(x-45,y+55);
				glVertex2f(x-45,y+55);
			glEnd();

			glBegin(GL_POLYGON);
				glVertex2f(x+20,y+65);
				glVertex2f(x+20,y+80);
				glVertex2f(x+30,y+80);
				glVertex2f(x+45,y+55);
				glVertex2f(x+45,y+55);
			glEnd();

			glBegin(GL_POLYGON);
				glVertex2f(x+40,y+65);
				glVertex2f(x+40,y+55);
				glVertex2f(x+70,y+60);
				glVertex2f(x+68,y+75);
			glEnd();

			glBegin(GL_POLYGON);
				glVertex2f(x-45,y+55);
				glVertex2f(x-35,y);
				glVertex2f(x-25,y);
				glVertex2f(x-35,y+58);
			glEnd();

			glBegin(GL_POLYGON); //Stick code
			glColor3f(0.2,0.0,0.02);
				glVertex2f(x+65,y-10);
				glVertex2f(x+72,y-10);
				glVertex2f(x+67,y+155);
			glEnd();
	
			//pant code

			glColor3f(0.24,0.5,0.0);
			glBegin(GL_POLYGON);
				glVertex2f(x-20,y);
				glVertex2f(x+20,y);
				glVertex2f(x+25,y-40);
				glVertex2f(x+10,y-40);
				glVertex2f(x,y-10);
				glVertex2f(x-10,y-40);
				glVertex2f(x-25,y-40);
				glVertex2f(x-20,y);
			glEnd();
		
			// legs code
			glColor3f(1.0,0.67,0.6);
			glBegin(GL_POLYGON);
				glVertex2f(x-25,y-40);
				glVertex2f(x-20,y-80);
				glVertex2f(x-15,y-80);
				glVertex2f(x-10,y-40);
			glEnd();
	
			glColor3f(1.0,0.67,0.6);
			glBegin(GL_POLYGON);
				glVertex2f(x-15,y-80);
				glVertex2f(x-20,y-80);
				glVertex2f(x-20,y-90);
				glVertex2f(x-15,y-90);
			glEnd();

			glColor3f(1.0,0.67,0.6);
			glBegin(GL_POLYGON);
				glVertex2f(x+25,y-40);
				glVertex2f(x+20,y-80);
				glVertex2f(x+15,y-80);
				glVertex2f(x+10,y-40);
			glEnd();
	
			glColor3f(1.0,0.67,0.6);
			glBegin(GL_POLYGON);
				glVertex2f(x+15,y-80);
				glVertex2f(x+20,y-80);
				glVertex2f(x+20,y-90);
				glVertex2f(x+15,y-90);
			glEnd();
		}


		void fish()
		{
			int x1=650, x2=650;
			int x3=200, x4=200;
			int y1=-80, y2=-80;

			//Fish 1
			glBegin(GL_POLYGON);
			glColor3f(1,0.549,0);
				glVertex2f(400+x3,200);
				glVertex2f(425+x4,220);
				glVertex2f(450+x3,200);
				glVertex2f(425+x4,180);
            glEnd();
		  
			glBegin(GL_POLYGON);
			glLineWidth(2.0);
			glColor3f(1,0.549,0);
				glVertex2f(437+x3,210);
				glVertex2f(457+x4,215);
				glVertex2f(457+x4,215);
				glVertex2f(437+x3,205);
			glEnd();

			glBegin(GL_POLYGON);
			glLineWidth(2.0);
			glColor3f(1,0.549,0);
				glVertex2f(437+x3,190);
				glVertex2f(457+x4,175);
				glVertex2f(457+x4,175);
				glVertex2f(444+x3,192);
			glEnd();

			//Fish2
			glBegin(GL_POLYGON);
			//glLineWidth(1.0);
			glColor3f(1,0.4980,0.3137);
				glVertex2f(400+x1,200+y1);
				glVertex2f(425+x2,220+y2);
				glVertex2f(450+x1,200+y1);
				glVertex2f(425+x2,180+y2);
			glEnd();
		  
			glBegin(GL_POLYGON);
			glLineWidth(2.0);
			glColor3f(1,0.4980,0.3137);;
				glVertex2f(437+x1,210+y1);
				glVertex2f(457+x2,215+y2);
				glVertex2f(457+x2,215+y2);
				glVertex2f(444+x1,205+y1);
			glEnd();

			glBegin(GL_POLYGON);
			glLineWidth(2.0);
			glColor3f(1,0.4980,0.3137);
				glVertex2f(437+x1,190+y1);
				glVertex2f(457+x2,175+y2);
				glVertex2f(457+x2,175+y2);
				glVertex2f(444+x1,192+y1);
			glEnd();
		}

		void rocks()
		{
			glColor3f(0.3,0.3,0.3);
				DrawCircle(0,0,90.0,50);
				DrawCircle(120,0,90.0,50);
				DrawCircle(100,120,80.0,50);
				DrawCircle(0,170,90.0,50);
		}	

		void display(void)
		{
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			glClearColor(0,0,0,1);
			init();
				
			//Sky
			glBegin(GL_POLYGON);
			glColor3f(0.6,0.88,1.0);
				glVertex2f(0,250);
				glVertex2f(0,1200);
			glColor3f(0.7,0.96,1.0);
				glVertex2f(1500,1200);
                glVertex2f(1500,250);
            glEnd();
				
			//Land
			glBegin(GL_POLYGON);        
			glColor3f(0.35,1.0,0.1);
				glVertex2f(0,250);
				glColor3f(0.8,0.3,0.0);
			    glVertex2f(0,900);
			glColor3f(0.8,0.3,0.0);
			    glVertex2f(1500,900);
			glColor3f(0.35,1.0,0.1);
				glVertex2f(1500,250);
            glEnd();

			mountains();
			
	        water();

			tree();
			
		    if(offset2<300)
				offset2+=0.31;	
			personMoving();

			if(offset1<350)
				offset1+=0.2;
			fishMoving();

			rocks();
			
            //Sun
            glBegin(GL_POLYGON);
			glColor3f(0.99,1.0,0.1);
				DrawCircle(670.0,1160.0,40.0,100);
            glEnd();

			glutPostRedisplay();
			glFlush();
		}

		// ResizeWindow is called when the window is resized
		static void resizeWindow(int w, int h)
		{
		    float aspectRatio;
			h = (h == 0) ? 1 : h;
			w = (w == 0) ? 1 : w;
			glViewport( 0, 0, w, h );	// View port uses whole window
			aspectRatio = (float)w/(float)h;

			// Set up the projection view matrix (not very well!)
			glMatrixMode( GL_PROJECTION );
			glLoadIdentity();
		    gluPerspective( 60.0, aspectRatio, 1.0, 30.0 );
	
			// Select the Modelview matrix
			glMatrixMode( GL_MODELVIEW );
		}
}life;

 class solar
{


public:
	void init()
		{
            glClearColor(0.0,0.0,0.0,0.0);
            glColor3f(1.0,0,0);
            glPointSize(3.0);
            glLineWidth(3.0);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
			gluOrtho2D(0,1500,0,1200);
		}

	void output(int x, int y, char *string,void *font)
{
	int len, i;

	glRasterPos2f(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++)
		glutBitmapCharacter(font, string[i]);
}

 void introduction()
{

	int pos=80;

	glColor3f(0,1,1);
	output(405, 600-pos, "The Solar System",fonts[2]);
	glColor3f(1,1,1);
	output(330,540-pos,"After the big bang, our Milky Way galaxy",fonts[2]);
	output(330,515-pos,"came into existence, where the solar system",fonts[2]);
	output(330,490-pos,"consists of 9 planets that revolve around the sun.",fonts[2]);
	glColor3f(0.752,0.752,0.752);
	output(375,400-pos,"Press '2' to view the Solar System.",fonts[3]);
}
   static void ResizeWindow(int w, int h)
{
    float aspectRatio;
	h = (h == 0) ? 1 : h;
	w = (w == 0) ? 1 : w;
	glViewport( 0, 0, w, h );	// View port uses whole window
	aspectRatio = (float)w/(float)h;

	// Set up the projection view matrix (not very well!)
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 60.0, aspectRatio, 1.0, 30.0 );

	// Select the Modelview matrix
    glMatrixMode( GL_MODELVIEW );
}

}solar;



 void *fonts2[]= 
{
	GLUT_BITMAP_9_BY_15,
	GLUT_BITMAP_TIMES_ROMAN_10,
	GLUT_BITMAP_TIMES_ROMAN_24,
	GLUT_BITMAP_HELVETICA_18,
	GLUT_BITMAP_HELVETICA_12
};


void output(int x, int y, char *string,void *font)
{
	int len, i;

	glRasterPos2f(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++)
		glutBitmapCharacter(font, string[i]);
}


void startpage()
{

    glColor3f(0.0,1.0,1.0);
	output(330,580, "Computer Graphics and Visualization Laboratory",fonts2[2]);
	output(470,550, "10CSL67",fonts2[3]);
	output(390,500, "The Big Bang: Origin of Life",fonts2[2]);
	output(380,450, "Submitted by:",fonts2[4]);
	glColor3f(1,1,1);
	output(440,420,"Jeet Kamdar",fonts2[3]);
	output(440,370,"Saatvik Doshi",fonts2[3]);
	output(440,320,"Vinayak Shivapuje",fonts2[3]);
    glColor3f(1,1,1);
    output(370,250," Press the space bar to view the menu.",fonts2[0]);
    glColor3f(0.752,0.752,0.752);
	output(440,400,"1DS12CS035",fonts2[0]);
	output(440,350,"1DS12CS081",fonts2[0]);
	output(440,300,"1DS14CS423",fonts2[0]);
}

void menu()
{
	pangaea.stars();
    pangaea.stars();
	glColor3f(0.0,1.0,1.0);
	output(390, 500, "The Big Bang: Origin of Life",fonts2[2]);
	glColor3f(0.1,0.1,0.1);	
    glColor3f(0.752,0.752,0.752);
	output(300,430,"Menu:",fonts2[3]);
	glColor3f(1,1,1);
	output(300,400,"a -> The Big Bang",fonts2[3]);
	output(300,370,"b -> Solar System",fonts2[3]);
	output(300,340,"c -> Natural disasters",fonts2[3]);
	output(300,310,"d -> Pangaea",fonts2[3]);
	output(300,280,"e -> Life on Earth",fonts2[3]);
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
	glLoadIdentity();
	pangaea.myInit();

	if(f == 1) //f=1 initially. Display startpage.
	   startpage();
	else if(f == 2) //Space bar
	   menu();
	else if(f == 3) //Key = a
		bigbang.introduction();
	else if (f == 4) //Key = b
		solar.introduction();
	else if (f == 5) //Key = c
		volcano.introduction();
	else if (f == 6) //Key = d
        pangaea.introduction();
	else if (f==7) //Key = e
		life.introduction();
	else if (f==8) //Key = 1
		bigbang.display();
	else if (f==9) //Key = 2
	{
		main2();
		glutDestroyWindow(window);
	}
	else if (f==10) //Key = 3
		volcano.display();
	else if (f==11) //Key = 4
	    pangaea.display();
	else if (f==12) //Key = 5
		life.display();

	glFlush();
	glutSwapBuffers();
}


void keyPressed(unsigned char key, GLint x, GLint )
{                
	if(key == ' ')
		f=2;
	else if(key == 'a')
		f=3;
	else if(key == 'b')
		f=4;
	else if(key == 'c')
		f=5;
	else if(key == 'd')
		f=6;
	else if(key == 'e') 
	    f=7;
	else if(key == 49) //Key = 1
		f=8;
	else if(key == 50) //Key = 2
		f=9;
	else if(key == 51) //Key = 3
		f=10;
	else if(key == 52) //Key = 4
	    f=11;
	else if(key == 53) //Key = 5
	    f=12;


	display();
}

void main3() 
{
//	glutInit(&argc, argv);            // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB| GLUT_DEPTH ); // Enable double buffered mode
	glutInitWindowSize(1000,700);   // Set the window's initial width & height
	glutInitWindowPosition(0,0); // Position the window's initial top-left corner
	window3 = glutCreateWindow("Solar System");          // Create window with the given title
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	glutReshapeFunc(life.resizeWindow);       // Register callback handler for window re-size event
	glutKeyboardFunc(keyPressed);
//	glutSpecialFunc(solar.SpecialKeyFunc);

	     
  
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
 
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	
	//glutMainLoop(); 
}


int main(int argc, char** argv) 
{
	glutInit(&argc, argv);            // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB| GLUT_DEPTH ); // Enable double buffered mode
	glutInitWindowSize(1500,1200);   // Set the window's initial width & height
	glutInitWindowPosition(0,0); // Position the window's initial top-left corner
	window = glutCreateWindow("Big Bang");          // Create window with the given title
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	glutReshapeFunc(life.resizeWindow);       // Register callback handler for window re-size event
	glutKeyboardFunc(keyPressed);
//	glutSpecialFunc(solar.SpecialKeyFunc);

	     
  
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
 
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	
	glutMainLoop(); 
    return 0;
}