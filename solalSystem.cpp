#include <GL/globals.h>
#include <GL/glut.h>
#include <GL/bigbang.h>
#include <GL/solarsys.h>  
#include <stdlib.h> 


 GLenum spinMode = GL_TRUE;
 GLenum singleStep = GL_FALSE;
int window2;

// control the animation's state and speed.
 float HourOfDay = 0.0;
 float DayOfYear = 0.0;
float AnimateIncrement = 7.0;  // Time step for animation (hours)
float x[210],y[210];

void SpecialKeyFunc( int Key, int x, int y )
{
	switch ( Key ) {
	case GLUT_KEY_UP:		
		Key_up();
		break;
	case GLUT_KEY_DOWN:
		Key_down();
		break;
	}
}


void Key_up(void)
{
    AnimateIncrement *= 2.0;			// Double the animation time step
}

void Key_down(void)
{
    AnimateIncrement /= 2.0;			// Halve the animation time step
	
}


void Animate(void)
{
	// Clear the redering window
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (spinMode) {
		// Update the animation state
        HourOfDay += AnimateIncrement;
        DayOfYear += AnimateIncrement/24.0;

        HourOfDay = HourOfDay - ((int)(HourOfDay/24))*24;
        DayOfYear = DayOfYear - ((int)(DayOfYear/365))*365;
		}
	
	// Clear the current matrix (Modelview)
    glLoadIdentity();

    glTranslatef ( 0.0, 0.0, -8.0 );

	glRotatef( 15.0, 1.0, 0.0, 0.0 );


	// Stars
	for(int i=0;i<200;i++)
	{
		glPushMatrix();
		glColor3f(1, 1, 1);
		glTranslatef(x[i],y[i],0.0);
		glutSolidSphere( 0.01, 15, 15);
		glPopMatrix();
	}

	
	// Draw the sun	-- as a yellow
	glColor3f( 1.0, 0.6, 0.0 );			
    glutSolidSphere( 1.0, 150, 150 );


    // Draw the Mercury
	// First position it around the sun
	//		Use DayOfYear to determine its position
	glPushMatrix();						// Save matrix state
    glRotatef( 360.0*DayOfYear/365.0, 0.0, 1.0, 0.0 );
    glTranslatef( -1.8, 0.0, 0.0 );
	// Second, rotate the earth on its axis.
	//		Use HourOfDay to determine its rotation.
	glRotatef( 360.0*HourOfDay/24.0, 0.0, 1.0, 0.0 );
	// Third, draw the earth as a wireframe sphere.
    glColor3f( 0.75, 0.75, 0.75 );
    glutSolidSphere( 0.08, 100, 100);
    glPopMatrix();						// Restore matrix state


	// Draw the Venus
	// First position it around the sun
	//		Use DayOfYear to determine its position
	glPushMatrix();						// Save matrix state
    glRotatef( 360.0*DayOfYear/365.0, 0.0, 1.0, 0.0 );
    glTranslatef( -1.8, 0.4, 1.0 );
	// Second, rotate the earth on its axis.
	//		Use HourOfDay to determine its rotation.
	glRotatef( 360.0*HourOfDay/24.0, 0.0, 1.0, 0.0 );
	// Third, draw the earth as a wireframe sphere.
    glColor3f( 0.9, 0.9, 0.0 );
    glutSolidSphere( 0.13, 100, 100);
    glPopMatrix();						// Restore matrix state

	// Draw the Mars
	// First position it around the sun
	//		Use DayOfYear to determine its position
	glPushMatrix();						// Save matrix state
    glRotatef( 360.0*DayOfYear/365.0, 0.2, 1.0, 0.0 );
    glTranslatef( 0.5, 0.0, 2.6 );
	// Second, rotate the earth on its axis.
	//		Use HourOfDay to determine its rotation.
	glRotatef( 360.0*HourOfDay/24.0, 0.0, 1.0, 0.0 );
	// Third, draw the earth as a wireframe sphere.
    glColor3f( 0.75, 0.164, 0.164 );
    glutSolidSphere( 0.16, 100, 100);
    glPopMatrix();						// Restore matrix state


	// Draw the Jupiter
	// First position it around the sun
	//		Use DayOfYear to determine its position
	glPushMatrix();						// Save matrix state
    glRotatef( 360.0*DayOfYear/365.0, 0.35, 0.9, -0.1 );
    glTranslatef( 2.9, -1.3, 0.6 );
	// Second, rotate the earth on its axis.
	//		Use HourOfDay to determine its rotation.
	glRotatef( 360.0*HourOfDay/24.0, 0.0, 1.0, 0.0 );
	// Third, draw the earth as a wireframe sphere.
    glColor3f( 1.0, 0.3, 0.1 );
    glutSolidSphere( 0.4, 100, 100);
    glPopMatrix();						// Restore matrix state



    // Draw the Saturn
	// First position it around the sun
	//		Use DayOfYear to determine its position
	glPushMatrix();						// Save matrix state
    glRotatef( 360.0*DayOfYear/365.0, 0.2, 0.8, 0.25 );
    glTranslatef( -3.9, 0.0, -1.0 );
	// Second, rotate the earth on its axis.
	//		Use HourOfDay to determine its rotation.
	glRotatef( 360.0*HourOfDay/24.0, 0.0, 1.0, 0.0 );
	// Third, draw the earth as a wireframe sphere.
    glColor3f( 0.8, 0.49, 0.19 );
    glutSolidSphere( 0.35, 100, 100);
    glPopMatrix();						// Restore matrix state


	// Draw the Uranus
	// First position it around the sun
	//		Use DayOfYear to determine its position
	glPushMatrix();						// Save matrix state
    glRotatef( 360.0*DayOfYear/365.0, 0.1, 0.9, -0.1 );
    glTranslatef( -4.0, 0.7, 0.0 );
	// Second, rotate the earth on its axis.
	//		Use HourOfDay to determine its rotation.
	glRotatef( 360.0*HourOfDay/24.0, 0.0, 1.0, 0.0 );
	// Third, draw the earth as a wireframe sphere.
    glColor3f( 0.4, 0.5, 0.85 );
    glutSolidSphere( 0.3, 100, 100);
    glPopMatrix();						// Restore matrix state



	// Draw the Neptune
	// First position it around the sun
	//		Use DayOfYear to determine its position
	glPushMatrix();						// Save matrix state
    glRotatef( 360.0*DayOfYear/365.0, 0.1, -0.9, -0.1 );
    glTranslatef( -4.2, 0.0, 0.0 );
	// Second, rotate the earth on its axis.
	//		Use HourOfDay to determine its rotation.
	glRotatef( 360.0*HourOfDay/24.0, 0.0, 1.0, 0.0 );
	// Third, draw the earth as a wireframe sphere.
    glColor3f( 0.2, 0.2, 1.0 );
    glutSolidSphere( 0.28, 100, 100);
    glPopMatrix();						// Restore matrix state


	// Draw the Pluto
	// First position it around the sun
	//		Use DayOfYear to determine its position
	glPushMatrix();						// Save matrix state
    glRotatef( 360.0*DayOfYear/365.0, 0.8, 0.3, 0.0 );
    glTranslatef( 0.0, 3.8, 0.0 );
	// Second, rotate the earth on its axis.
	//		Use HourOfDay to determine its rotation.
	glRotatef( 360.0*HourOfDay/24.0, 0.0, 1.0, 0.0 );
	// Third, draw the earth as a wireframe sphere.
    glColor3f( 0.7, 0.5, 0.5 );
    glutSolidSphere( 0.08, 100, 100);
    glPopMatrix();						// Restore matrix state


    // Draw the Earth
	// First position it around the sun
	//		Use DayOfYear to determine its position
    glRotatef( 360.0*DayOfYear/365.0, 0.0, 1.0, 0.0 );
    glTranslatef( 2.0, 0.0, 0.0 );
    glPushMatrix();						// Save matrix state
	// Second, rotate the earth on its axis.
	//		Use HourOfDay to determine its rotation.
	glRotatef( 360.0*HourOfDay/24.0, 0.0, 1.0, 0.0 );
	// Third, draw the earth as a wireframe sphere.
    glColor3f( 0.2, 0.4, 1.0 );
    glutSolidSphere( 0.13, 100, 100);
    glPopMatrix();						// Restore matrix state

	// Draw the moon.
	//	Use DayOfYear to control its rotation around the earth
   	glRotatef( 360.0*12.0*DayOfYear/365.0, 0.0, 0.5, 0.0 );
    glTranslatef( 0.4, 0.0, 0.0 );
    glColor3f( 0.85, 0.85, 1.0 );
    glutSolidSphere( 0.05, 100, 100 );

	   


	// Flush the pipeline, and swap the buffers
    //glFlush();
    glutSwapBuffers();

	if ( singleStep ) {
		spinMode = GL_FALSE;
	}

	glutPostRedisplay();		// Request a re-draw for animation purposes

}

// Initialize OpenGL's rendering modes
void OpenGLInit(void)
{
    glShadeModel( GL_FLAT );
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    glClearDepth( 1.0 );
    glEnable( GL_DEPTH_TEST );
}

// ResizeWindow is called when the window is resized
void ResizeWindow(int w, int h)
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


const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f }; 
 
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f }; 



void keyPressed2(unsigned char key, GLint x, GLint y)
{
	if (key == 27)
	{
	 f=2;
	 main3();
	 glutDestroyWindow(window2);
	}
}
	


// Main routine
// Set up OpenGL, hook up callbacks, and start the main loop
void main2()
{
	// Need to double buffer for animation
	//glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );

	// Create and position the graphics window
    glutInitWindowPosition( 0, 0 );
    glutInitWindowSize(1000,700);
    window2=glutCreateWindow( "Solar System Demo" );

	// Initialize OpenGL.
    OpenGLInit();

	int rand(),nx,ny;
	//Stars
	for ( int i = 0; i < 200; i ++ ) 
	{
		x[i] = rand()%1000;
		y[i] = rand()%700;
		nx = rand()%2;
		ny = rand()%2;
		x[i]=x[i]/100;
		y[i]=y[i]/100;
		
		if(nx == 1)
			x[i] = x[i] * -1;
		if(ny == 1)
			y[i] = y[i] * -1;
	
	
	}


	// Set up callback functions for key presses
	glutSpecialFunc( SpecialKeyFunc );

	// Set up the callback function for resizing windows
    glutReshapeFunc(ResizeWindow);

	// Callback for graphics image redrawing
    glutDisplayFunc( Animate );

	glutKeyboardFunc(keyPressed2);


	

    //Effects
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK); 
 
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS); 
 
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING); 
  
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
 
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	
	// Start the main loop.  glutMainLoop never returns.
	
//glutMainLoop();
} 
