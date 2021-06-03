/*
#define _SORT
#include"libOne.h"
void gmain() {
	window(1100, 1000, full);
	const int num = 20;
	int score[num];
	int r, c;
	while (notQuit) {
		clear(60);

		if (isTrigger(KEY_D)) {
			for (int i = 0;i < num;i++) {
				score[i] = random() % 1001;
			}
		}

		if (isTrigger(KEY_A)) {
			for (r = 0;r < num - 1;r++) {
				for (c = r + 1;c < num; c++) {
					if (score[r] < score[c]) {
						int w = score[r];
						score[r] = score[c];
						score[c] = w;
					}
				}
			}
		}
		
		for (int i = 0;i < num;i++) {
			print(score[i]);
			rect(100, 50 * i, score[i], 40);
		}
	}
}
*/
/*
#define _SHOOT
#ifdef _SHOOT
#include"libOne.h"
void gmain() {
	window(1920, 1080, full);
	struct PLAYER {
		float px, py, vx, w, h;
	};
	struct BULLET {
		float px, py, vy, w, h;
		int hp = 0;
	};
	struct PLAYER p;
		p.px = width / 2;
		p.py = height - 150;
		p.vx = 20;
		p.w = 80;
		p.h = 200;
		const int numbullets = 10;
	struct BULLET b[numbullets];
	for (int i = 0;i < numbullets;i++) {
		b[i].px = p.px;
		b[i].py = p.py;
		b[i].w = 40;
		b[i].h = 40;
		b[i].vy = 15;
	}
	while (notQuit) {
		clear(3,252, 227);
		rectMode(CENTER);
		if (isPress(KEY_D)) { p.px += p.vx; }
		if (isPress(KEY_A)) { p.px += -p.vx; }
		if (isTrigger(KEY_SPACE)) {
			for (int i = 0;i < numbullets;i++) {
				if (b[i].hp == 0) {
					b[i].py = p.py;
					b[i].px = p.px;
					b[i].hp = 1;
					i = numbullets;
				}
			}
		}
		for (int i = 0;i < numbullets;i++) {
			if (b[i].hp > 0) {
				b[i].py += -b[i].vy;
				if (b[i].py < -b[i].h) {
					b[i].hp = 0;
				}
			}
		}
		rect(p.px, p.py, p.w, p.h);
		for (int i = 0;i < numbullets;i++) {
			if (b[i].hp > 0) {
				rect(b[i].px, b[i].py, b[i].w, b[i].h);
			}
		}

	}
}
*/
/*
#include"libOne.h"
void gmain() {
	window(1920, 1080, full);
	struct PLAYER {
		float px, py, w, h, vx,ofsY;
	};
	struct BULLET {
		float px, py, w, h, vy,hp;
	};
	struct PLAYER p;
	p.px = width / 2;
	p.py = height - 150;
	p.w = 100;
	p.h = 150;
	p.vx = 10;
	p.ofsY = p.h / 2;
	const int numbullet = 1500;
	struct BULLET b[numbullet];
	for (int i = 0;i < numbullet;i++) {
		b[i].px = p.px;
		b[i].py = p.py;
		b[i].w = 30;
		b[i].h = 30;
		b[i].vy = -0.1;
		b[i].hp = 0;
	}
	float angle = 0;
	while (notQuit) {
		angle += 0.1f;
		clear(3, 252, 277);
		for (int i = 0;i < numbullet;i++) {
			if (isTrigger(KEY_J)) { b[i].vy = -100; }
		}
		for (int i = 0;i < numbullet;i++) {
			if (isTrigger(KEY_F)) { b[i].vy = -0.1; }
		}
		if (isPress(KEY_D)) {p.px += p.vx;}
		if (isPress(KEY_A)) { p.px += -p.vx; }
		if (isPress(KEY_SPACE)) {
			for (int i = 0;i < numbullet;i++) {
				if (b[i].hp == 0) { 
					b[i].hp = 1;
					b[i].px = p.px;
					b[i].py = p.py + p.ofsY;
					i = numbullet;
				}
			}
		}
		for (int i = 0;i < numbullet;i++) {
			if (b[i].hp > 0) {
				b[i].py += b[i].vy;
				if (b[i].py < -b[i].h) {
					b[i].hp = 0;
				}
			}
		}
		rectMode(CENTER);
		rect(p.px , p.py, p.w, p.h);
		for (int i = 0;i < numbullet;i++) {
		    if (b[i].hp > 0) {
				rect(b[i].px, b[i].py + b[i].vy, b[i].w, b[i].h, angle);
		    }
		}
	}
}
*/
/*
#include"libOne.h"
#include"FACE.h"
void gmain() {
	window(1920, 1080, full);
	float px = width / 2;
	float py = height / 2;
	float angle = 0;
	float ofsX = 100;
	float ofsY = 100;
	int sw = 0;
	while (notQuit) {
		ofsX =width/2- mouseX;
			ofsY =height/2- mouseY;
		angle += 0.01f;
		clear(3, 252, 227);
		if (isTrigger(KEY_SPACE)) { sw = 1 - sw; }
		for (int i = -10;i <= 5;i++) {
			if (sw == 0) {
				roundFace(px+ofsX*i, py+ofsY*i);
			}
			if (sw == 1) {
				squareFace(px+ofsX*i, py+ofsY*i, angle);
			}
		}
	}
}
/*


/*
#include"libOne.h"
void gmain() {
	window(1920, 1080, full);
	struct COLOR green = { 0,255,0 };
	struct COLOR yellow = { 255,255,0 };
	struct COLOR red = { 255,0,0 };
	struct COLOR color = green;

	float hpMax = 700;
	float hp = hpMax;
	float hpWarnig = hpMax * 0.4f;
	float hpDenger = hpMax * 0.2f;
    float px = 700;
    float py = height/2;
	float h = 60;
	while (notQuit) {
		if (isTrigger(KEY_SPACE)) { hp = hpMax; }
		clear(74, 84, 89);
			fill(128);
			rect(px, py, hpMax, h);
		if (hp > 0) { hp -= 2; }

		if (hp > hpWarnig) { color = green; }
		else if (hp > hpDenger) { color = yellow; }
		else color = red;
		fill(color);
			rect(px, py, hp, h);
		if (hp == 0) {
			textSize(100);
			text("GAMEOVER",700,400);
		}
	}

}
*/

/*#include"libOne.h"
void gmain() {
	window(1920, 1080, full);
	int life = 5;
	float px = 400;
	float py = 200;
	float radius = 100;
	float space = 200;
	while (notQuit) {
		if (isTrigger(KEY_A)) { life += -1; }
		if (isTrigger(KEY_D)) { life += 1; }
		clear(74, 84, 89);
		print((let)"life=" + life);
		int i = 0;
		while (i<life) {
			float offsetX = space * i;
			fill(3, 252, 227);
			circle(px+offsetX, py, radius * 2);
			i++;
		}
		for (int i = 0;i<life ;i++){
			float offsetX = space * i;
			float offsetY = space * 1;
			fill(252, 227, 3);
			circle(px + offsetX, py+offsetY, radius * 2);
		}
		for (int i = 0;i < life;i++) {
			float offsetX = space * i;
			float offsetY = space * 2;
			fill(277, 3, 252);
			circle(px + offsetX, py + offsetY, radius * 2);
		}
	}

}
*/

/*
#include"libOne.h"
void gmain() {
	window(1920, 1080, full);
	float px = 1920 / 2;
	float py = 1080 / 2;
	float vx = 10;
	float radius = 150;
	float len = radius / 1.414f * 2;
	float sw = radius / 10;
	float angle = 0;
	float angleSpeed = 0.03f;

	while (notQuit) {
		px += vx;
		angle += angleSpeed;
		if (px > 1920||px<0) {
			vx = -vx; 
			angleSpeed = -angleSpeed;
		}
		clear(227);
		fill(3, 252, 277);
		strokeWeight(sw);
		stroke(0, 0, 255,128);
		rectMode(CENTER);
		circle(px, py, radius * 2);
		rect(px, py, len, len, angle);
		strokeWeight(sw * 4);
		point(px, py);
		strokeWeight(sw / 2);
		line(px, py, 1920 / 2, 0);
	}
	
}
*/

