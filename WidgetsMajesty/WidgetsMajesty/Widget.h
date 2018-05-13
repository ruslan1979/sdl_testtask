#pragma once
#include <string>

using namespace std;

class Widget {
public:
	void setId(const string & id); // установить строковый идентификатор

	void setOrder(int order); // для изменения порядка отрисовки виджетов на экране (аппаратный z-order не используется)

	void setPos(float x, float y); // положение виджета
	void setSize(float w, float h); // размер виджета. Предполагается что все виджеты – прямоугольники

	void onPressLMouseButton(void); // нажатие левой кнопки мыши
	void onReleaseLMouseButton(void); // отпускание левой кнопки мыши
	void onEnterLMouseButton(void); // попадание мыши в виджет
	void onLeaveLMouseButton(void); // выход мыши за пределы виджета
	bool update(float dt); // обновление состояния виджета
	void render(void); // отрисовка виджета

	void show(); // показать виджет
	void hide(); // скрыть виджет
	void addEventHandler(); // регистрация функций обратного вызова для различных событий виджета. Параметры требуется продумать самостоятельно

};
