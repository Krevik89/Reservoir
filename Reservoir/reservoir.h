#pragma once
#include<iostream>
using namespace std;


class reservoir
{
    char _name[50];
    double _length, _width, _depth;
    char _type[50];
    friend class Savefile;
public:
    //����������� � �����������
    reservoir(const char* name, double l, double w, double d, const char* type)
    {
        strcpy_s(_name, name);
        _length = l;
        _width = w;
        _depth = d;
        strcpy_s(_type, type);
    }

    //����������� �� ���������
    reservoir() :reservoir("No name", 0., 0., 0., "No type") {}

    //����������� �����������
    reservoir(const reservoir& p) {
        strcpy_s(_name, p._name);
        _length = p._length;
        _width = p._width;
        _depth = p._depth;
        strcpy_s(_type, p._type);
    }

    //����������
    ~reservoir() {}

    //������ ��� ������������ ������ � ������� � ������ �� �����
    void volume() {
        unsigned long long a = this->_length * this->_width * this->_depth;
        cout << "����� " << this->_name << " = " << a << endl;

    }

    void Area() {
        cout << "������� " << this->_name << " = " << this->_length * this->_width << endl;
    }

    void print() {
        cout << "��������: " << this->_name << "\n"
            << "�����: " << this->_length << "\n"
            << "������: " << this->_width << "\n"
            << "�������: " << this->_depth << "\n"
            << "��� �������: " << this->_type << endl;;
    }
    
    //����� ��� �������� �����
    friend bool operator==(reservoir& p, reservoir& p1) {
        if (strcmp(p._type, p1._type) == 0) {
            return true;
        }
        else return false;
    }

    //����� ��� ��������� ������� ������ ����������� �������� ������ ����
    bool operator>(const reservoir& s1) const {
        return strcmp(this->_type, s1._type) == 0 && this->_length*this->_width > s1._length*s1._width;
    }
    bool operator<(const reservoir& s1) const {
        return strcmp(this->_type, s1._type) == 0 && this->_length * this->_width < s1._length * s1._width;
    }
    bool operator!=(const reservoir& p)const {
        return strcmp(this->_type, p._type) == 0 && this->_length * this->_width != p._length * p._width;
    }

    //����� ��� ����������� ��������
    reservoir& operator=(const reservoir& p) {
        strcpy_s(this->_name, p._name);
        this->_length = p._length;
        this->_width = p._width;
        this->_depth = p._depth;
        strcpy_s(this->_type, p._type);
        return *this;
    }

    //����� ��� ���������� � ��������
    void Add(reservoir* p,int* s) {
        reservoir s1;
        cout << "������� ��������\n";
        gets_s(s1._name);
        cout << "������� �����\n";
        cin >> s1._length;
        cout << "������� ������\n";
        cin >> s1._width;
        cout << "������� �������\n";
        cin >> s1._depth;
        cout << "������� ���\n"; cin.ignore(); gets_s(s1._type);
        p[*s] = s1;
        (*s)++;
    }
    void del(reservoir* p, int* s, int index) {
        if (index >= 0 && index < *s) {
            for (int i = index; i < *s - 1; i++) {
                strcpy_s(p[i]._name, p[i + 1]._name);
                p[i]._length = p[i + 1]._length;
                p[i]._width = p[i + 1]._width;
                p[i]._depth = p[i + 1]._depth;
                strcpy_s(p[i]._type, p[i + 1]._type);
            }
            (*s)--;
        }
    }
    /*
    
    � ��������� ����, �������� ����.*/


};

