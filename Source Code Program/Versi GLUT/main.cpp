#include <Windows.h>
#include <GL/glut.h>
#include <math.h>

void jalanan(), garis_jalanan(), circle(),
car_from_left(), car_from_right(), gedung(),
ovo_logo(), rumah_sakit_logo(), cloud(), langit(),
jalankan_car_from_left(), jalankan_car_from_right();

float v1_x; float v1_y;
float v2_x; float v2_y;
float v3_x; float v3_y;
float v4_x; float v4_y;

//========================== MEMBUAT LINGKARAN ========================== 
void circle(float x, float y, float r, int a, int b, int c)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3ub(a, b, c);;
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + r * cos(th), y + r * sin(th));
    }
    glEnd();
}
//========================== MEMBUAT LANGIT ========================== 
void langit() {
    glBegin(GL_POLYGON);
    glColor3ub(135, 206, 250); glVertex2f(-1, 1);   // warna light sky blue
    glColor3ub(135, 206, 250); glVertex2f(1, 1);    // warna light sky blue
    glColor3ub(0, 255, 127); glVertex2f(1, 0);      // warna spring green
    glColor3ub(0, 255, 127); glVertex2f(-1, 0);     // warna spring green
    glEnd();
}
//========================== MEMBUAT AWAN ========================== 
void cloud(float x, float y) {
    circle(x - 0.05, y, 0.05, 245, 245, 245);                        // warna white smoke
    circle(x, y, 0.05, 245, 245, 245);                              // warna white smoke
    circle(x + 0.05, y, 0.05, 245, 245, 245);                       // warna white smoke
    circle(((x - 0.05) + x) / 2, y + 0.05, 0.05, 245, 245, 245);    // warna white smoke
}
//========================== MEMBUAT JALANAN ========================== 
void jalanan(float v1_x, float v1_y,
    float v2_x, float v2_y,
    float v3_x, float v3_y,
    float v4_x, float v4_y) {
    glBegin(GL_POLYGON);
    glColor3ub(127, 127, 127);      // warna grey50 atau abu-abu
    glVertex2f(v1_x, v1_y);
    glVertex2f(v2_x, v2_y);
    glVertex2f(v3_x, v3_y);
    glVertex2f(v4_x, v4_y);
    glEnd();
}
//========================== MEMBUAT GARIS JALANAN ========================== 
void garis_jalanan() {
    float n = -0.8;
    while (n < 1) {
        glBegin(GL_LINE_STRIP);
        glColor3ub(255, 255, 255);  // warna grey100 atau white
        glVertex2f(n, -0.5);
        glVertex2f(n + 0.1, -0.5);
        glEnd();
        n += 0.3;
    }
}
//========================== MEMBUAT POHON ========================== 
void tree(float x, float y) {
    //membuat batang pohon
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);     // warna chocolate4
    glVertex2f(x - 0.025, y + 0.2);
    glVertex2f(x + 0.025, y + 0.2);
    glVertex2f(x + 0.025, y);
    glVertex2f(x - 0.025, y);
    glEnd();
    //membuat daun-daun pohon
    circle(x - 0.05, y + 0.15, 0.075, 34, 139, 34);                 // warna forest green 
    circle(x, y + 0.15, 0.075, 34, 139, 34);                        // warna forest green
    circle(x + 0.05, y + 0.15, 0.075, 34, 139, 34);                 // warna forest green
    circle((x + (x + 0.05)) / 2, y + 0.25, 0.075, 34, 139, 34);     // warna forest green
    circle((x + (x - 0.05)) / 2, y + 0.25, 0.075, 34, 139, 34);     // warna forest green
    x = (((x + (x + 0.05)) / 2) + ((x + (x - 0.05)) / 2)) / 2;  // membuat titik x untuk daun paling atas
    circle(x, y + 0.35, 0.075, 34, 139, 34);
}
//========================== MEMBUAT GEDUNG ========================== 
void gedung(float x, float y,
    int a, int b, int c) {
    v1_x = x - 0.1; v1_y = y + 0.45;
    v2_x = x + 0.25; v2_y = y + 0.45;
    v3_x = x + 0.25; v3_y = y;
    v4_x = x - 0.1; v4_y = y;
    //membuat bandungan dasar gedung
    glColor3ub(a, b, c);
    glBegin(GL_POLYGON);
    glVertex2f(v1_x, v1_y);
    glVertex2f(v2_x, v2_y);
    glVertex2f(v3_x, v3_y);
    glVertex2f(v4_x, v4_y);
    glEnd();
    //membuat pintu gedung
    v1_x = x - 0.025; v1_y = y + 0.1;
    v2_x = x + 0.175; v2_y = y + 0.1;
    v3_x = x + 0.175; v3_y = y;
    v4_x = x - 0.025; v4_y = y;
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 255); glVertex2f(v1_x, v1_y);    // warna cyan
    glColor3ub(255, 255, 255); glVertex2f(v2_x, v2_y);  // warna putih
    glColor3ub(0, 255, 255); glVertex2f(v3_x, v3_y);    // warna cyan
    glColor3ub(255, 255, 255); glVertex2f(v4_x, v4_y);  // warna putih
    glEnd();
    //membuat gagang pintu kiri
    v1_x = x + 0.055; v1_y = y + 0.075;
    v2_x = x + 0.06; v2_y = y + 0.075;
    v3_x = x + 0.06; v3_y = y + 0.035;
    v4_x = x + 0.055; v4_y = y + 0.035;
    glBegin(GL_POLYGON);
    glColor3ub(127, 127, 127); glVertex2f(v1_x, v1_y);  // warna grey50     
    glColor3ub(255, 255, 255); glVertex2f(v2_x, v2_y);  // warna white
    glColor3ub(127, 127, 127); glVertex2f(v3_x, v3_y);  // warna grey50     
    glColor3ub(127, 127, 127); glVertex2f(v4_x, v4_y);  // warna grey50
    glEnd();
    //membuat gagang pintu kanan
    v1_x = x + 0.09; v1_y = y + 0.075;
    v2_x = x + 0.095; v2_y = y + 0.075;
    v3_x = x + 0.095; v3_y = y + 0.035;
    v4_x = x + 0.09; v4_y = y + 0.035;
    glBegin(GL_POLYGON);
    glColor3ub(127, 127, 127); glVertex2f(v1_x, v1_y);  // warna grey50     
    glColor3ub(255, 255, 255); glVertex2f(v2_x, v2_y);  // warna white
    glColor3ub(127, 127, 127); glVertex2f(v3_x, v3_y);  // warna grey50     
    glColor3ub(127, 127, 127); glVertex2f(v4_x, v4_y);  // warna grey50
    glEnd();
    //================ membuat kaca gedung ================
    // ====================================================
    float v1_v4_x = x - 0.1;
    float v2_v3_x = x + 0.25;
    float i;
    ///================ membuat kaca gedung KIRI ================
    v1_v4_x = x - 0.1;
    v2_v3_x = x + 0.25;
    i = 0.4;
    v1_v4_x += 0.025;    //-0.1 + 0.025 = -0.075
    v2_v3_x -= 0.195;    //0.25 - 0.195 = 0.055
    // range antara v1_v4_x dan v2_v3_x 
    // 0.055 - (-0.075) = 0.13
    while (i > 0.1) {
        v1_x = v1_v4_x; v1_y = y + i;
        v2_x = v2_v3_x; v2_y = y + i;
        i -= 0.05;
        v3_x = v2_v3_x; v3_y = y + i;
        v4_x = v1_v4_x; v4_y = y + i;
        i -= 0.05;
        glBegin(GL_POLYGON);
        glColor3ub(135, 206, 250); glVertex2f(v1_x, v1_y);     // warna light skyblue
        glColor3ub(255, 255, 255); glVertex2f(v2_x, v2_y);     // warna grey100 atau white
        glColor3ub(135, 206, 250); glVertex2f(v3_x, v3_y);     // warna light skyblue
        glColor3ub(255, 255, 255); glVertex2f(v4_x, v4_y);     // warna grey100 atau white
        glEnd();
    }
    ///================ membuat kaca gedung KANAN ================
    v1_v4_x = x - 0.1;
    v2_v3_x = x + 0.25;
    i = 0.4;
    v1_v4_x += 0.195;         //-0.1 + 0.195 = 0.095
    v2_v3_x -= 0.025;         //0.25 - 0.025 = 0.225
    // range antara v1_v4_x dan v2_v3_x
    // 0.225 - 0.095 = 0.13
    while (i > 0.1) {
        v1_x = v1_v4_x; v1_y = y + i;
        v2_x = v2_v3_x; v2_y = y + i;
        i -= 0.05;
        v3_x = v2_v3_x; v3_y = y + i;
        v4_x = v1_v4_x; v4_y = y + i;
        i -= 0.05;
        glBegin(GL_POLYGON);
        glColor3ub(135, 206, 250); glVertex2f(v1_x, v1_y);     // warna light skyblue
        glColor3ub(255, 255, 255); glVertex2f(v2_x, v2_y);     // warna grey100 atau white
        glColor3ub(135, 206, 250); glVertex2f(v3_x, v3_y);     // warna light skyblue
        glColor3ub(255, 255, 255); glVertex2f(v4_x, v4_y);     // warna grey100 atau white
        glEnd();
    }
}
//========================== MEMBUAT LOGO OVO =========================
void ovo_logo(float x, float y) {
    circle(x - 0.1, y, 0.05, 85, 26, 139);      // warna purple4
    circle(x - 0.1, y, 0.035, 255, 255, 255);   // warna white
    circle(x - 0.1, y, 0.020, 85, 26, 139);     // warna purple4

    //membuat tulisan OVO
    //membuat huruf O
    circle(x, y, 0.035, 85, 26, 139);     // warna purple4
    circle(x, y, 0.020, 255, 255, 255);   // warna white
    //membuat huruf V 
    //============= V KIRI =============
    v1_x = x + 0.035; v1_y = y + 0.025;
    v2_x = x + 0.050; v2_y = y + 0.025;
    v3_x = x + 0.080; v3_y = y - 0.020;
    v4_x = x + 0.080; v4_y = y - 0.045;
    glColor3ub(85, 26, 139);            // warna purple4
    glBegin(GL_POLYGON);
    glVertex2f(v1_x, v1_y);
    glVertex2f(v2_x, v2_y);
    glVertex2f(v3_x, v3_y);
    glVertex2f(v4_x, v4_y);
    glEnd();
    //============= V KANAN =============
    v1_x = x + 0.080; v1_y = y - 0.020;
    v2_x = x + 0.110; v2_y = y + 0.025;
    v3_x = x + 0.125; v3_y = y + 0.025;
    v4_x = x + 0.080; v4_y = y - 0.045;
    glColor3ub(85, 26, 139);            // warna purple4
    glBegin(GL_POLYGON);
    glVertex2f(v1_x, v1_y);
    glVertex2f(v2_x, v2_y);
    glVertex2f(v3_x, v3_y);
    glVertex2f(v4_x, v4_y);
    glEnd();
    //membuat huruf O
    circle(x + 0.16, y, 0.035, 85, 26, 139);     // warna purple4
    circle(x + 0.16, y, 0.020, 255, 255, 255);   // warna white
}
//========================== MEMBUAT LOGO RUMAH SAKIT =========================
void rumah_sakit_logo(float x, float y) {
    circle(x, y, 0.06, 0, 0, 0);             // warna black
    circle(x, y, 0.05, 255, 255, 255);       // warna white
    //membuat batang tegak
    v1_x = x - 0.025; v1_y = y + 0.035;
    v2_x = x + 0.025; v2_y = y + 0.035;
    v3_x = x + 0.025; v3_y = y - 0.035;
    v4_x = x - 0.025; v4_y = y - 0.035;
    glColor3ub(255, 0, 0);      //warna red
    glBegin(GL_POLYGON);
    glVertex2f(v1_x, v1_y);
    glVertex2f(v2_x, v2_y);
    glVertex2f(v3_x, v3_y);
    glVertex2f(v4_x, v4_y);
    glEnd();
    //membuat batang tiduran
    x = ((v1_x)+(v2_x)) / 2;
    y = ((v2_y)+(v3_y)) / 2;
    v1_x = x - 0.040; v1_y = y + 0.020;
    v2_x = x + 0.040; v2_y = y + 0.020;
    v3_x = x + 0.040; v3_y = y - 0.020;
    v4_x = x - 0.040; v4_y = y - 0.020;
    glColor3ub(255, 0, 0);      //warna red
    glBegin(GL_POLYGON);
    glVertex2f(v1_x, v1_y);
    glVertex2f(v2_x, v2_y);
    glVertex2f(v3_x, v3_y);
    glVertex2f(v4_x, v4_y);
    glEnd();
}
//========================== MEMBUAT MOBIL MUNCUL DARI KIRI ========================== 
void car_from_left(float v1_x, float v1_y,
    float v2_x, float v2_y,
    float v3_x, float v3_y,
    float v4_x, float v4_y,
    int a, int b, int c) {

    //membuat badan mobil
    glColor3ub(a, b, c);
    glBegin(GL_POLYGON);
    glVertex2f(v1_x, v1_y);
    glVertex2f(v2_x, v2_y);
    glVertex2f(v3_x, v3_y);
    glVertex2f(v4_x, v4_y);
    glEnd();
    //membuat bagian atas mobil
    glColor3ub(a, b, c);
    glBegin(GL_POLYGON);
    glVertex2f(v1_x + 0.025, v1_y + 0.1);
    glVertex2f(v2_x - 0.1, v2_y + 0.1);
    glVertex2f(v2_x - 0.05, v2_y);
    glVertex2f(v1_x, v1_y);
    glEnd();
    //membuat kaca depan mobil
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255); glVertex2f(v1_x + 0.2, v1_y + 0.075);    // warna white
    glColor3ub(176, 226, 255); glVertex2f(v2_x - 0.125, v2_y + 0.075);  // warna lightskyblue1
    glColor3ub(176, 226, 255); glVertex2f(v2_x - 0.075, v2_y);          // warna lightskyblue1
    glColor3ub(255, 255, 255); glVertex2f(v1_x + 0.2, v1_y);            // warna white
    glEnd();
    //membuat kaca belakang mobil
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255); glVertex2f(v1_x + 0.030, v1_y + 0.075);  // warna white
    glColor3ub(176, 226, 255); glVertex2f(v2_x - 0.225, v2_y + 0.075);  // warna lightskyblue1
    glColor3ub(176, 226, 255); glVertex2f(v2_x - 0.225, v2_y);          // warna lightskyblue1
    glColor3ub(255, 255, 255); glVertex2f(v1_x + 0.030, v1_y);          // warna white
    glEnd();
    //membuat roda depan
    circle(v2_x - 0.1, v4_y, 0.05, 0, 0, 0);            // warna black
    circle(v2_x - 0.1, v4_y, 0.025, 255, 255, 255);     // warna white
    //membuat roda belakang
    circle(v4_x + 0.1, v4_y, 0.05, 0, 0, 0);            // warna black
    circle(v4_x + 0.1, v4_y, 0.025, 255, 255, 255);     // warna white
}
//========================== MEMBUAT MOBIL MUNCUL DARI KANAN ========================== 
void car_from_right(float v1_x, float v1_y,
    float v2_x, float v2_y,
    float v3_x, float v3_y,
    float v4_x, float v4_y,
    int a, int b, int c) {

    //membuat badan mobil
    glColor3ub(a, b, c);
    glBegin(GL_POLYGON);
    glVertex2f(v1_x, v1_y);
    glVertex2f(v2_x, v2_y);
    glVertex2f(v3_x, v3_y);
    glVertex2f(v4_x, v4_y);
    glEnd();
    //membuat bagian atas mobil
    glColor3ub(a, b, c);
    glBegin(GL_POLYGON);
    glVertex2f(v1_x + 0.1, v1_y + 0.1);
    glVertex2f(v2_x - 0.05, v2_y + 0.1);
    glVertex2f(v2_x, v2_y);
    glVertex2f(v1_x + 0.05, v1_y);
    glEnd();
    //membuat kaca depan mobil
    glBegin(GL_POLYGON);
    glColor3ub(176, 226, 255); glVertex2f(v1_x + 0.125, v1_y + 0.075);  // warna lightskyblue1
    glColor3ub(255, 255, 255); glVertex2f(v2_x - 0.20, v2_y + 0.075);  // warna white
    glColor3ub(255, 255, 255); glVertex2f(v2_x - 0.20, v2_y);           // warna white
    glColor3ub(176, 226, 255); glVertex2f(v1_x + 0.075, v1_y);          // warna lightskyblue1
    glEnd();
    //membuat kaca belakang mobil
    glBegin(GL_POLYGON);
    glColor3ub(176, 226, 255); glVertex2f(v1_x + 0.225, v1_y + 0.075);  // warna lightskyblue1
    glColor3ub(255, 255, 255); glVertex2f(v2_x - 0.05, v2_y + 0.075);  // warna white
    glColor3ub(255, 255, 255); glVertex2f(v2_x - 0.05, v2_y);           // warna white
    glColor3ub(176, 226, 255); glVertex2f(v1_x + 0.225, v1_y);          // warna lightskyblue1
    glEnd();
    //membuat roda depan
    circle(v4_x + 0.1, v4_y, 0.05, 0, 0, 0);            // warna black
    circle(v4_x + 0.1, v4_y, 0.025, 255, 255, 255);     // warna white
    //membuat roda belakang
    circle(v2_x - 0.1, v4_y, 0.05, 0, 0, 0);            // warna black
    circle(v2_x - 0.1, v4_y, 0.025, 255, 255, 255);     // warna white
}
//========================== MEMBUAT MOBIL DARI KIRI BERJALAN ========================== 
GLfloat position1 = 0;  //posisi dimana objek berada + posisi(koordinat x untuk translated) 
GLfloat speed1 = 0.05f;
void jalankan_car_from_left(int value) {
    if (position1 > 1.75) {
        position1 = -1.45;
    }
    position1 += speed1;
    glutPostRedisplay();
    glutTimerFunc(100, jalankan_car_from_left, 0);
}
//========================== MEMBUAT MOBIL DARI kanan BERJALAN ========================== 
GLfloat position2 = 0; //posisi dimana objek berada + posisi(koordinat x untuk translated)
GLfloat speed2 = 0.05f;
void jalankan_car_from_right(int value) {
    if (position2 < -1.75) {
        position2 = 1.75;
    }
    position2 -= speed2;
    glutPostRedisplay();
    glutTimerFunc(100, jalankan_car_from_right, 0);
}
void display(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    langit();
    //membuat MATAHARI
    circle(0.45, 0.90, 0.075, 255, 255, 0);     // warna yellow 
    cloud(-0.7, 0.65);
    cloud(-0.4, 0.85);
    cloud(0.4, 0.85);
    cloud(0.7, 0.65);
    tree(-1, 0);
    tree(0.95, 0);
    jalanan(-1, 0,
        1, 0,
        1, -1,
        -1, -1);
    jalanan(-0.35, 0.2,
        -0.10, 0.2,
        -0.10, 0,
        -0.35, 0);
    jalanan(0.40, 0.2,
        0.15, 0.2,
        0.15, 0,
        0.40, 0);
    garis_jalanan();
    tree(0.025, 0.1);
    gedung(-0.3, 0.1, 255, 165, 0);     // warna orange
    gedung(0.2, 0.1, 255, 174, 185);    // warna lightpink1
    tree(-0.50, 0.1);
    tree(0.55, 0.1);
    //membuat gedung ovo
    gedung(-0.8, 0, 255, 250, 240);     // warna FloralWhite
    ovo_logo(-0.75, 0.475);
    //membuat gedung rumah sakit
    gedung(0.7, 0, 0, 0, 255);          // warna blue
    rumah_sakit_logo(0.775, 0.475);
    //membuat mobil yang muncul dari kiri
    glPushMatrix();
    glTranslated(position1, 0, 0);
    car_from_left(-0.85, -0.25,
        -0.45, -0.25,
        -0.45, -0.40,
        -0.85, -0.40,
        0, 255, 0);         // warna green
    glPopMatrix();

    glPushMatrix();
    glTranslated(position1, 0, 0);
    car_from_left(0.15, -0.25,
        0.55, -0.25,
        0.55, -0.40,
        0.15, -0.40,
        238, 130, 238);     // warna violet
    glPopMatrix();

    //membuat mobil yang muncul dari kanan
    glPushMatrix();
    glTranslated(position2, 0, 0);
    car_from_right(0.5, -0.65,
        0.9, -0.65,
        0.9, -0.80,
        0.5, -0.80,
        255, 0, 0);        // warna red
    glPopMatrix();

    glPushMatrix();
    glTranslated(position2, 0, 0);
    car_from_right(-0.85, -0.65,
        -0.45, -0.65,
        -0.45, -0.80,
        -0.85, -0.80,
        255, 255, 0);        // warna yellow
    glPopMatrix();

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInitWindowSize(700, 700);                   // fungsi untuk mengatur ukuran jendela
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("City View_Trijudi Mualajati Sianturi_57418142");
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);               // fungsi untuk mengatur ukuran area tampilan
    glutDisplayFunc(display);                       // fungsi untuk menampilkan gambar yang sudah kita bungkus didalam 1 fungsi yaitu fungsi display
    glutTimerFunc(100, jalankan_car_from_left, 0);  // fungsi untuk menjalankan mobil yang muncul dari kiri
    glutTimerFunc(100, jalankan_car_from_right, 0); // fungsi untuk menjalankan mobil yang muncul dari kanan
    glutMainLoop();                                 // fungsi untuk menjalankan progran utama secara terus menerus
    return 0;
}
