#include <iostream>
#include <vector>
#include <string>

using namespace std;


//전방선언에서는 m_name이 있는지를 알수 없음 -> 함수를 밖으로 빼야함
class Doctor;

//환자와 닥터는 서로를 가지고있음

class Patient
{
private:
	string m_name;
	vector<Doctor*> m_doctors;

public:
	Patient(string name_in)
		:m_name(name_in)
	{}

	void addDoctor(Doctor* new_doctor)
	{
		m_doctors.push_back(new_doctor);
	}

	void meetDoctors();

	friend class Doctor;
};

class Doctor
{
private:
	string m_name;
	vector<Patient*> m_patient;

public:
	Doctor(string name_in)
		:m_name(name_in)
	{}

	void addPatient(Patient* new_patient)
	{
		m_patient.push_back(new_patient);
	}

	void meetPatients()
	{
		for (auto& element : m_patient)
		{
			//Doctor의 이름에 접근을 못하고 있음
			cout << "Meet Patient:" << element->m_name << endl;
		}
	}
	friend class Patient;

};
 
void Patient::meetDoctors()
{
	for (auto& element : m_doctors)
	{
		//Doctor의 이름에 접근을 못하고 있음 -> friend class 선언
		//전방선언에도 불구하고 m_name의 존재를 모름 -> 멤버함수를 밖으로 빼냄
		cout << "Meet doctor:" << element->m_name << endl;
	}
}



int main()
{
	Patient* p1 = new Patient("Shin");
	Patient* p2 = new Patient("Kim");
	Patient* p3 = new Patient("Salah");

	Doctor* d1 = new Doctor("Dr.J");
	Doctor* d2 = new Doctor("Dr.Q");

	p1->addDoctor(d1);
	d1->addPatient(p1);

	p2->addDoctor(d2);
	d2->addPatient(p2);

	p2->addDoctor(d1);
	d1->addPatient(p2);

	p1->meetDoctors();

	d1->meetPatients();

	delete p1;
	delete p2;
	delete p3;

	delete d1;
	delete d2;
}
