#pragma once
#ifndef WIDGET_H
#define WIDGET_H

#include <set>
#include <string>
#include "EventHandler.h"

using namespace std;

class Widget {
private:
	string widgetId;
	int widgetOrder;
	float widgetX, widgetY;
	float widgetW, widgetH;
	set<EventHandler*> widgetHandlers;
public:
	void setId(const string & id); // ���������� ��������� �������������

	void setOrder(int order); // ��� ��������� ������� ��������� �������� �� ������ (���������� z-order �� ������������)

	void setPos(float x, float y); // ��������� �������
	void setSize(float w, float h); // ������ �������. �������������� ��� ��� ������� � ��������������

	void onPressLMouseButton(void); // ������� ����� ������ ����
	void onReleaseLMouseButton(void); // ���������� ����� ������ ����
	void onEnterLMouseButton(void); // ��������� ���� � ������
	void onLeaveLMouseButton(void); // ����� ���� �� ������� �������
	bool update(float dt); // ���������� ��������� �������
	void render(void); // ��������� �������

	void show(); // �������� ������
	void hide(); // ������ ������
	void addEventHandler(EventHandler*); // ����������� ������� ��������� ������ ��� ��������� ������� �������. ��������� ��������� ��������� ��������������

};

#endif