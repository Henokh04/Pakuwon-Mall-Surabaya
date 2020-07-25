#include <windows.h>
#include <iostream>
#include <GL/freeglut.h>
#include <math.h>
#include <stdlib.h.>


void init(void);
void hasil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
static int year1 = 0, day1 = 0, year2 = 0, day2 = 0;
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;

int i;

bool mouseDown = false;

int is_depth;
float w(int x) {
    float hasil = x;
    if (x >= 255) {
        hasil = 255;
    }
    else if (x <= 0) {
        hasil = 0;
    };
    return (float)hasil / 255;
};
float c[100][4] = { {w(0),w(127),w(255),1.0f},
                    {w(255),w(127),w(0),1.0f}
};
void tabung(float radatas, float radbawah, float tinggi, float x, float y, float z, float atas[4], float selimut[4], float bawah[4], int mulai, int stop) {
    float theta, theti;
    int i, j;

    if (mulai <= 0) {
        mulai = 0;
    }
    else if (mulai >= 360) {
        mulai = 360;
    };
    if (stop <= 0) {
        stop = 0;
    }
    else if (stop >= 360) {
        stop = 360;
    };

    glPushMatrix();//bawah
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor4f(bawah[0], bawah[1], bawah[2], bawah[3]);
    for (i = mulai; i < stop; i++) {
        theta = i * 3.14 / 180;
        glVertex3f(x + radbawah * cos(theta), y, z + radbawah * sin(theta));
    };
    glEnd();
    //selimut
    glBegin(GL_POLYGON);
    glColor4f(selimut[0], selimut[1], selimut[2], selimut[3]);
    for (i = mulai; i < stop; i++) {
        theta = i * 3.14 / 180;
        if (i == 359) {
            j = 0;
        }
        else {
            j = i + 1;
        };
        theti = j * 3.14 / 180;
        glVertex3f(x + radatas * cos(theta), y + tinggi, z + radatas * sin(theta));
        glVertex3f(x + radatas * cos(theti), y + tinggi, z + radatas * sin(theti));
        glVertex3f(x + radbawah * cos(theti), y, z + radbawah * sin(theti));
        glVertex3f(x + radbawah * cos(theta), y, z + radbawah * sin(theta));
    };
    glEnd();
    //atas
    glBegin(GL_POLYGON);
    glColor4f(atas[0], atas[1], atas[2], atas[3]);
    for (i = mulai; i < stop; i++) {
        theta = i * 3.14 / 180;
        glVertex3f(x + radatas * cos(theta), y + tinggi, z + radatas * sin(theta));
    };
    glEnd();
    glPopMatrix();
    glPopMatrix();
}


void tabung2(float radatas, float radbawah, float tinggi, float x, float y, float z, float atas[4], float selimut[4], float bawah[4], int mulai, int stop) {
    float theta, theti;
    int i, j;

    if (mulai <= 0) {
        mulai = 0;
    }
    else if (mulai >= 360) {
        mulai = 360;
    };
    if (stop <= 0) {
        stop = 0;
    }
    else if (stop >= 360) {
        stop = 360;
    };

    glPushMatrix();
    //selimut
    glBegin(GL_POLYGON);
    glColor4f(selimut[0], selimut[1], selimut[2], selimut[3]);
    for (i = mulai; i < stop; i++) {
        theta = i * 3.14 / 180;
        if (i == 359) {
            j = 0;
        }
        else {
            j = i + 1;
        };
        theti = j * 3.14 / 180;
        glVertex3f(x - radatas * cos(theta), y + tinggi, z - radatas * sin(theta));
        glVertex3f(x - radatas * cos(theti), y + tinggi, z - radatas * sin(theti));
        glVertex3f(x - radbawah * cos(theti), y, z - radbawah * sin(theti));
        glVertex3f(x - radbawah * cos(theta), y, z - radbawah * sin(theta));
    };
    glEnd();
    glPopMatrix();
}


void gedungpanjang()
{
    //gedungkanan
    glBegin(GL_QUADS);
    glColor4f(0.1f, 0.1f, 0.1f, 0.1f);
    glVertex3f(20.0, -35.0, 0.0);
    glVertex3f(20.0, -12.0, 0.0);
    glVertex3f(0.0, -12.0, 0.0);
    glVertex3f(0.0, -35.0, 0.0);

    glVertex3f(20.0, -12.0, 0.0);
    glVertex3f(20.0, -12.0, -3.0);
    glVertex3f(0.0, -12.0, -3.0);
    glVertex3f(0.0, -12.0, 0.0);

    glEnd();
    //gedungtengah
    
    glBegin(GL_QUADS);
    glColor4f(0.1f, 0.1f, 0.1f, 0.1f);
    glVertex3f(-30.0, -35.0, -65.0);
    glVertex3f(-30.0, -12.0, -65.0);
    glVertex3f(-30.0, -12.0, -30.0);
    glVertex3f(-30.0, -35.0, -30.0);

    glVertex3f(-30.0, 11.0, -15.0);
    glVertex3f(-30.0, 11.0, -70.0);
    glVertex3f(50.0, 11.0, -70.0);
    glVertex3f(50.0, 11.0, -15.0);

    glColor4f(0.1f, 0.1f, 0.1f, 0.1f);
    glVertex3f(50.0, -35.0, -65.0);
    glVertex3f(50.0, -12.0, -65.0);
    glVertex3f(50.0, -12.0, -30.0);
    glVertex3f(50.0, -35.0, -30.0);
    glEnd();

    //gedungkanan
    glBegin(GL_QUADS);
    glColor4f(0.1f, 0.1f, 0.1f, 0.1f);
    glVertex3f(20.0, -35.0, -95.0);
    glVertex3f(20.0, -12.0, -95.0);
    glVertex3f(0.0, -12.0, -95.0);
    glVertex3f(0.0, -35.0, -95.0);

    glVertex3f(20.0, -12.0, -95.0);
    glVertex3f(20.0, -12.0, -98.0);
    glVertex3f(0.0, -12.0, -98.0);
    glVertex3f(0.0, -12.0, -95.0);

    glEnd();

    ////gedungnaik1
    glBegin(GL_QUADS);
    glColor4f(0.1f, 0.1f, 0.1f, 0.1f);
    glVertex3f(-30.0, -20.0, 1.0);
    glVertex3f(-30.0, 130.0, 1.0);
    glVertex3f(-15.0, 130.0, 1.0);
    glVertex3f(-15.0, -20.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.1f, 0.1f, 0.1f, 0.1f);
    glVertex3f(-30.0, -20.0, 1.0);
    glVertex3f(-30.0, 130.0, 1.0);
    glVertex3f(-30.0, 130.0, -26.0);
    glVertex3f(-30.0, -20.0, -26.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.1f, 0.1f, 0.1f, 0.1f);
    glVertex3f(-30.0, -20.0, -26.0);
    glVertex3f(-30.0, 130.0, -26.0);
    glVertex3f(-15.0, 130.0, -26.0);
    glVertex3f(-15.0, -20.0, -26.0);
    glEnd();

    ////gedungnaik2
    glBegin(GL_QUADS);
    glColor4f(0.1f, 0.1f, 0.1f, 0.1f);
    glVertex3f(30.0, -20.0, -26.0);
    glVertex3f(30.0, 130.0, -26.0);
    glVertex3f(45.0, 130.0, -26.0);
    glVertex3f(45.0, -20.0, -26.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.1f, 0.1f, 0.1f, 0.1f);
    glVertex3f(45.0, -20.0, 1.0);
    glVertex3f(45.0, 130.0, 1.0);
    glVertex3f(45.0, 130.0, -26.0);
    glVertex3f(45.0, -20.0, -26.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.1f, 0.1f, 0.1f, 0.1f);
    glVertex3f(30.0, -20.0, 1.0);
    glVertex3f(30.0, 130.0, 1.0);
    glVertex3f(45.0, 130.0, 1.0);
    glVertex3f(45.0, -20.0, 1.0);
    glEnd();

    //tengahkanan

    glBegin(GL_QUADS);
    glColor4f(0.15f, 0.15f, 0.15f, 0.15f);
    glVertex3f(30.0, -20.0, 1.0);
    glVertex3f(30.0, 130.0, 1.0);
    glVertex3f(30.0, 130.0, -2.0);
    glVertex3f(30.0, -20.0, -2.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.15f, 0.15f, 0.15f, 0.15f);
    glVertex3f(30.0, -20.0, -23.0);
    glVertex3f(30.0, 130.0, -23.0);
    glVertex3f(30.0, 130.0, -26.0);
    glVertex3f(30.0, -20.0, -26.0);
    glEnd();

    //tengahngah

    glBegin(GL_QUADS);
    glColor4f(0.2f, 0.2f, 0.2f, 0.2f);
    glVertex3f(30.0, -20.0, -23.0);
    glVertex3f(30.0, 130.0, -23.0);
    glVertex3f(-15.0, 130.0, -23.0);
    glVertex3f(-15.0, -20.0, -23.0);
    glEnd();



    glBegin(GL_QUADS);
    glColor4f(0.2f, 0.2f, 0.2f, 0.2f);
    glVertex3f(30.0, -20.0, -2.0);
    glVertex3f(30.0, 130.0, -2.0);
    glVertex3f(-15.0, 130.0, -2.0);
    glVertex3f(-15.0, -20.0, -2.0);
    glEnd();
    //tengahkiri

    glBegin(GL_QUADS);
    glColor4f(0.15f, 0.15f, 0.15f, 0.15f);
    glVertex3f(-15.0, -20.0, -26.0);
    glVertex3f(-15.0, 130.0, -26.0);
    glVertex3f(-15.0, 130.0, -23.0);
    glVertex3f(-15.0, -20.0, -23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.15f, 0.15f, 0.15f, 0.15f);
    glVertex3f(-15.0, -20.0, 1.0);
    glVertex3f(-15.0, 130.0, 1.0);
    glVertex3f(-15.0, 130.0, -2.0);
    glVertex3f(-15.0, -20.0, -2.0);
    glEnd();

    //atap

    glBegin(GL_QUADS);
    glColor4f(0.3f, 0.3f, 0.3f, 0.3f);
    glVertex3f(-30.0, 130.0, -26.0);
    glVertex3f(-30.0, 130.0, 1.0);
    glVertex3f(-15.0, 130.0, 1.0);
    glVertex3f(-15.0, 130.0, -26.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor4f(0.3f, 0.3f, 0.3f, 0.3f);
    glVertex3f(30.0, 130.0, -26.0);
    glVertex3f(30.0, 130.0, 1.0);
    glVertex3f(45.0, 130.0, 1.0);
    glVertex3f(45.0, 130.0, -26.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.3f, 0.3f, 0.3f, 0.3f);
    glVertex3f(30.0, 130.0, -23.0);
    glVertex3f(30.0, 130.0, -2.0);
    glVertex3f(-15.0, 130.0, -2.0);
    glVertex3f(-15.0, 130.0, -23.0);
    glEnd();

    //gedungnaiklagi
    glBegin(GL_QUADS);
    glColor4f(0.1f, 0.1f, 0.1f, 0.1f);
    glVertex3f(-15.0, -20.0, -91.0);
    glVertex3f(-15.0, 130.0, -91.0);
    glVertex3f(45.0, 130.0, -91.0);
    glVertex3f(45.0, -20.0, -91.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.1f, 0.1f, 0.1f, 0.1f);
    glVertex3f(45.0, -20.0, -66.0);
    glVertex3f(45.0, 130.0, -66.0);
    glVertex3f(45.0, 130.0, -91.0);
    glVertex3f(45.0, -20.0, -91.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.15f, 0.15f, 0.15f, 0.15f);
    glVertex3f(-15.0, -20.0, -66.0);
    glVertex3f(-15.0, 130.0, -66.0);
    glVertex3f(45.0, 130.0, -66.0);
    glVertex3f(45.0, -20.0, -66.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.2f, 0.2f, 0.2f, 0.2f);
    glVertex3f(-15.0, 130.0, -66.0);
    glVertex3f(-15.0, 130.0, -91.0);
    glVertex3f(45.0, 130.0, -91.0);
    glVertex3f(45.0, 130.0, -66.0);
    glEnd();

    ///lampu
    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 128.0, -2.0);
    glVertex3f(-30.0, 110.0, -2.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 128.0, -5.0);
    glVertex3f(-30.0, 110.0, -5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 128.0, -8.0);
    glVertex3f(-30.0, 110.0, -8.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 128.0, -11.0);
    glVertex3f(-30.0, 110.0, -11.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 128.0, -14.0);
    glVertex3f(-30.0, 110.0, -14.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 128.0, -17.0);
    glVertex3f(-30.0, 110.0, -17.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 128.0, -20.0);
    glVertex3f(-30.0, 110.0, -20.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 128.0, -23.0);
    glVertex3f(-30.0, 110.0, -23.0);
    glEnd();
    /// <jendela2>
    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, 108.0, -3.5);
    glVertex3f(-30.0, 90.0, -3.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, 108.0, -6.5);
    glVertex3f(-30.0, 90.0, -6.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, 108.0, -9.5);
    glVertex3f(-30.0, 90.0, -9.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, 108.0, -12.5);
    glVertex3f(-30.0, 90.0, -12.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, 108.0, -15.5);
    glVertex3f(-30.0, 90.0, -15.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, 108.0, -18.5);
    glVertex3f(-30.0, 90.0, -18.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, 108.0, -21.5);
    glVertex3f(-30.0, 90.0, -21.5);
    glEnd();
    ///jendela3&4
    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 88.0, -2.0);
    glVertex3f(-30.0, 70.0, -2.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 88.0, -5.0);
    glVertex3f(-30.0, 70.0, -5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 88.0, -8.0);
    glVertex3f(-30.0, 70.0, -8.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 88.0, -11.0);
    glVertex3f(-30.0, 70.0, -11.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 88.0, -14.0);
    glVertex3f(-30.0, 70.0, -14.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 88.0, -17.0);
    glVertex3f(-30.0, 70.0, -17.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 88.0, -20.0);
    glVertex3f(-30.0, 70.0, -20.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 88.0, -23.0);
    glVertex3f(-30.0, 70.0, -23.0);
    glEnd();
    /// <jendela2>
    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, 68.0, -3.5);
    glVertex3f(-30.0, 50.0, -3.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, 68.0, -6.5);
    glVertex3f(-30.0, 50.0, -6.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, 68.0, -9.5);
    glVertex3f(-30.0, 50.0, -9.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, 68.0, -12.5);
    glVertex3f(-30.0, 50.0, -12.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, 68.0, -15.5);
    glVertex3f(-30.0, 50.0, -15.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, 68.0, -18.5);
    glVertex3f(-30.0, 50.0, -18.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, 68.0, -21.5);
    glVertex3f(-30.0, 50.0, -21.5);
    glEnd();
    //jendela selanjutnya
    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 48.0, -2.0);
    glVertex3f(-30.0, 30.0, -2.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 48.0, -5.0);
    glVertex3f(-30.0, 30.0, -5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 48.0, -8.0);
    glVertex3f(-30.0, 30.0, -8.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 48.0, -11.0);
    glVertex3f(-30.0, 30.0, -11.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 48.0, -14.0);
    glVertex3f(-30.0, 30.0, -14.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 48.0, -17.0);
    glVertex3f(-30.0, 30.0, -17.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 48.0, -20.0);
    glVertex3f(-30.0, 30.0, -20.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 48.0, -23.0);
    glVertex3f(-30.0, 30.0, -23.0);
    glEnd();

    /// <jendela2>
    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, 28.0, -3.5);
    glVertex3f(-30.0, 10.0, -3.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, 28.0, -6.5);
    glVertex3f(-30.0, 10.0, -6.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, 28.0, -9.5);
    glVertex3f(-30.0, 10.0, -9.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, 28.0, -12.5);
    glVertex3f(-30.0, 10.0, -12.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, 28.0, -15.5);
    glVertex3f(-30.0, 10.0, -15.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, 28.0, -18.5);
    glVertex3f(-30.0, 10.0, -18.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-30.0, 28.0, -21.5);
    glVertex3f(-30.0, 10.0, -21.5);
    glEnd();

    //jendela selanjutnya
    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 8.0, -2.0);
    glVertex3f(-30.0, -10.0, -2.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 8.0, -5.0);
    glVertex3f(-30.0, -10.0, -5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 8.0, -8.0);
    glVertex3f(-30.0, -10.0, -8.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 8.0, -11.0);
    glVertex3f(-30.0, -10.0, -11.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 8.0, -14.0);
    glVertex3f(-30.0, -10.0, -14.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 8.0, -17.0);
    glVertex3f(-30.0, -10.0, -17.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 8.0, -20.0);
    glVertex3f(-30.0, -10.0, -20.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-30.0, 8.0, -23.0);
    glVertex3f(-30.0, -10.0, -23.0);
    glEnd();
    ///jendela naik lagi2
    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 128.0, -2.0);
    glVertex3f(45.0, 110.0, -2.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 128.0, -5.0);
    glVertex3f(45.0, 110.0, -5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 128.0, -8.0);
    glVertex3f(45.0, 110.0, -8.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 128.0, -11.0);
    glVertex3f(45.0, 110.0, -11.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 128.0, -14.0);
    glVertex3f(45.0, 110.0, -14.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 128.0, -17.0);
    glVertex3f(45.0, 110.0, -17.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 128.0, -20.0);
    glVertex3f(45.0, 110.0, -20.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 128.0, -23.0);
    glVertex3f(45.0, 110.0, -23.0);
    glEnd();
    ///jendela2
    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(45.0, 108.0, -3.5);
    glVertex3f(45.0, 90.0, -3.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(45.0, 108.0, -6.5);
    glVertex3f(45.0, 90.0, -6.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(45.0, 108.0, -9.5);
    glVertex3f(45.0, 90.0, -9.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(45.0, 108.0, -12.5);
    glVertex3f(45.0, 90.0, -12.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(45.0, 108.0, -15.5);
    glVertex3f(45.0, 90.0, -15.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(45.0, 108.0, -18.5);
    glVertex3f(45.0, 90.0, -18.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(45.0, 108.0, -21.5);
    glVertex3f(45.0, 90.0, -21.5);
    glEnd();
    ///jendela3&4
    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 88.0, -2.0);
    glVertex3f(45.0, 70.0, -2.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 88.0, -5.0);
    glVertex3f(45.0, 70.0, -5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 88.0, -8.0);
    glVertex3f(45.0, 70.0, -8.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 88.0, -11.0);
    glVertex3f(45.0, 70.0, -11.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 88.0, -14.0);
    glVertex3f(45.0, 70.0, -14.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 88.0, -17.0);
    glVertex3f(45.0, 70.0, -17.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 88.0, -20.0);
    glVertex3f(45.0, 70.0, -20.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 88.0, -23.0);
    glVertex3f(45.0, 70.0, -23.0);
    glEnd();
    /// <jendela2>
    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(45.0, 68.0, -3.5);
    glVertex3f(45.0, 50.0, -3.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(45.0, 68.0, -6.5);
    glVertex3f(45.0, 50.0, -6.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(45.0, 68.0, -9.5);
    glVertex3f(45.0, 50.0, -9.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(45.0, 68.0, -12.5);
    glVertex3f(45.0, 50.0, -12.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(45.0, 68.0, -15.5);
    glVertex3f(45.0, 50.0, -15.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(45.0, 68.0, -18.5);
    glVertex3f(45.0, 50.0, -18.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(45.0, 68.0, -21.5);
    glVertex3f(45.0, 50.0, -21.5);
    glEnd();
    //jendela selanjutnya
    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 48.0, -2.0);
    glVertex3f(45.0, 30.0, -2.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 48.0, -5.0);
    glVertex3f(45.0, 30.0, -5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 48.0, -8.0);
    glVertex3f(45.0, 30.0, -8.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 48.0, -11.0);
    glVertex3f(45.0, 30.0, -11.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 48.0, -14.0);
    glVertex3f(45.0, 30.0, -14.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 48.0, -17.0);
    glVertex3f(45.0, 30.0, -17.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 48.0, -20.0);
    glVertex3f(45.0, 30.0, -20.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 48.0, -23.0);
    glVertex3f(45.0, 30.0, -23.0);
    glEnd();


    /// <jendela2>
    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(45.0, 28.0, -3.5);
    glVertex3f(45.0, 10.0, -3.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(45.0, 28.0, -6.5);
    glVertex3f(45.0, 10.0, -6.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(45.0, 28.0, -9.5);
    glVertex3f(45.0, 10.0, -9.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(45.0, 28.0, -12.5);
    glVertex3f(45.0, 10.0, -12.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(45.0, 28.0, -15.5);
    glVertex3f(45.0, 10.0, -15.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(45.0, 28.0, -18.5);
    glVertex3f(45.0, 10.0, -18.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(45.0, 28.0, -21.5);
    glVertex3f(45.0, 10.0, -21.5);
    glEnd();

    //jendela selanjutnya
    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 8.0, -2.0);
    glVertex3f(45.0, -10.0, -2.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 8.0, -5.0);
    glVertex3f(45.0, -10.0, -5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 8.0, -8.0);
    glVertex3f(45.0, -10.0, -8.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 8.0, -11.0);
    glVertex3f(45.0, -10.0, -11.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 8.0, -14.0);
    glVertex3f(45.0, -10.0, -14.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 8.0, -17.0);
    glVertex3f(45.0, -10.0, -17.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 8.0, -20.0);
    glVertex3f(45.0, -10.0, -20.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(45.0, 8.0, -23.0);
    glVertex3f(45.0, -10.0, -23.0);
    glEnd();

    //lampugedung2
    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-19.8, 128.0, -67.0);
    glVertex3f(-19.8, 110.0, -67.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-24.2, 128.0, -70.0);
    glVertex3f(-24.2, 110.0, -70.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-26.4, 128.0, -73.0);
    glVertex3f(-26.4, 110.0, -73.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f,0.0f, 0.0f, 0.0f);
    glVertex3f(-27.5, 128.0, -76.0);
    glVertex3f(-27.5, 110.0, -76.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-27.5, 128.0, -79.0);
    glVertex3f(-27.5, 110.0, -79.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-27.2, 128.0, -82.0);
    glVertex3f(-27.2, 110.0, -82.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-25.8, 128.0, -85.0);
    glVertex3f(-25.8, 110.0, -85.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-23.2, 128.0, -88.0);
    glVertex3f(-23.2, 110.0, -88.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-19.8, 128.0, -90.0);
    glVertex3f(-19.8, 110.0, -90.0);
    glEnd();
    /// <jendela2>
    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-21.8, 108.0, -67.5);
    glVertex3f(-21.8, 90.0, -67.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-24.8, 108.0, -70.5);
    glVertex3f(-24.8, 90.0, -70.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-26.5, 108.0, -73.5);
    glVertex3f(-26.5, 90.0, -73.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-27.4, 108.0, -76.5);
    glVertex3f(-27.4, 90.0, -76.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-27.5, 108.0, -79.5);
    glVertex3f(-27.5, 90.0, -79.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-26.8, 108.0, -82.5);
    glVertex3f(-26.8, 90.0, -82.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-26.0, 108.0, -85.5);
    glVertex3f(-26.0, 90.0, -85.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-23.5, 108.0, -88.5);
    glVertex3f(-23.5, 90.0, -88.5);
    glEnd();
    //merah
    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-19.8, 88.0, -67.0);
    glVertex3f(-19.8, 70.0, -67.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-24.2, 88.0, -70.0);
    glVertex3f(-24.2, 70.0, -70.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-26.4, 88.0, -73.0);
    glVertex3f(-26.4, 70.0, -73.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-27.5, 88.0, -76.0);
    glVertex3f(-27.5, 70.0, -76.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-27.5, 88.0, -79.0);
    glVertex3f(-27.5, 70.0, -79.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-27.2, 88.0, -82.0);
    glVertex3f(-27.2, 70.0, -82.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-25.8, 88.0, -85.0);
    glVertex3f(-25.8, 70.0, -85.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-23.2, 88.0, -88.0);
    glVertex3f(-23.2, 70.0, -88.0);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-19.8, 88.0, -90.0);
    glVertex3f(-19.8, 70.0, -90.0);
    glEnd();

    //ungu
    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-21.8, 68.0, -67.5);
    glVertex3f(-21.8, 50.0, -67.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-24.8, 68.0, -70.5);
    glVertex3f(-24.8, 50.0, -70.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-26.5, 68.0, -73.5);
    glVertex3f(-26.5, 50.0, -73.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-27.4, 68.0, -76.5);
    glVertex3f(-27.4, 50.0, -76.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-27.5, 68.0, -79.5);
    glVertex3f(-27.5, 50.0, -79.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-26.8, 68.0, -82.5);
    glVertex3f(-26.8, 50.0, -82.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-26.0, 68.0, -85.5);
    glVertex3f(-26.0, 50.0, -85.5);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
    glVertex3f(-23.5, 68.0, -88.5);
    glVertex3f(-23.5, 50.0, -88.5);
    glEnd();

    //lamputengah
    glBegin(GL_LINES);
    glColor4f(1.0f, 1.0f, 0.6f, 0.0f);
    glVertex3f(8.0, -13.0, -1.0);
    glVertex3f(8.0, 130.0, -1.0);
    
    glVertex3f(10.0, -13.0, -1.0);
    glVertex3f(10.0, 130.0, -1.0);

    glVertex3f(9.0, 55.0, -1.0);
    glVertex3f(9.0, 62.0, -1.0);
    

    glVertex3f(11.0, 55.0, -1.0);
    glVertex3f(11.0, 62.0, -1.0);

    glVertex3f(7.0, 55.0, -1.0);
    glVertex3f(7.0, 62.0, -1.0);
    glEnd();

    //lamputengah2
    glBegin(GL_LINES);
    glColor4f(1.0f, 1.0f, 0.6f, 0.0f);
    glVertex3f(8.0, -13.0, -23.0);
    glVertex3f(8.0, 130.0, -23.0);

    glVertex3f(10.0, -13.0, -23.0);
    glVertex3f(10.0, 130.0, -23.0);

    glVertex3f(9.0, 55.0, -23.0);
    glVertex3f(9.0, 62.0, -23.0);


    glVertex3f(11.0, 55.0, -23.0);
    glVertex3f(11.0, 62.0, -23.0);

    glVertex3f(7.0, 55.0, -23.0);
    glVertex3f(7.0, 62.0, -23.0);
    glEnd();

    
}
void hasil(void)
{
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);
    gedungpanjang();
    



    glPushMatrix();
    tabung(25.0f, 25.0f, 23.0f, -25.0, -12.0, -45.0, c[255], c[255], c[255], 0, 360);
    tabung(25.0f, 25.0f, 23.0f, 45.0, -12.0, -45.0, c[255], c[255], c[255], 0, 360);
    glRotatef(-90, 0.0, 1.0, 0.0);
    //gedungtinggi
    tabung(12.5f, 12.5f, 150.0f, -78.5, -20.0, 15.0, c[255], c[255], c[255], 0, 180);
    //gedungutama
    tabung(25.0f, 25.0f, 23.0f, -10.0, -35.0, 20.0, c[255], c[255], c[255], 0, 360);
    tabung(25.0f, 25.0f, 40.0f, -80.0, -35.0, 20.0, c[255], c[255], c[255], 0, 360);
    tabung(25.0f, 25.0f, 23.0f, -10.0, -35.0, -40.0, c[255], c[255], c[255], 0, 360);
    tabung(25.0f, 25.0f, 40.0f, -80.0, -35.0, -40.0, c[255], c[255], c[255], 0, 360);
 
     glPopMatrix();
    


    glutSwapBuffers();
}

void idle() {
    if (!mouseDown) {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y) {
    if (mouseDown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

    } glutPostRedisplay();
}
void init(void)
{
    glClearColor(0.5, 0.5, 1.0, 0.5);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glPointSize(6.0);
    glLineWidth(3.0f);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    is_depth = 1;
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(3.0, 0.0, 0.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case 'a':
    case 'A':
        glTranslatef(-3.0, 0.0, 0.0);
        break;
    case 'j':
    case 'J':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case 'l':
    case 'L':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case 'i':
    case 'I':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case 'k':
    case 'K':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;    
    case '2':
        glTranslatef(0.0, 3.0, 0.0);
        break;
    case '3':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case '4':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '5':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
   
    }
    hasil();

}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;
    GLfloat aspect = (GLfloat)lebar / (GLfloat)tinggi;
    glViewport(0, 0, lebar, tinggi);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(-20.0, -5.0, -200.0);
    glMatrixMode(GL_MODELVIEW);
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1400, 750);
    glutInitWindowPosition(70, 70);
    glutCreateWindow("Pakuwon Mall Surabaya");
    init();
    glutDisplayFunc(hasil);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}