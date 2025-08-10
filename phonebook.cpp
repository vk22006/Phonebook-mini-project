// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Kishore V

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <iostream>
#include <map>
#include <string>

namespace py = pybind11;

class Phonebook {
    private:
        std::map<std::string, long long> contact;
    public:
        Phonebook() = default;
        Phonebook(const std::map<std::string, long long> &initial) {
            contact = initial;
        }
        void add_contact(const std::string &name, const long long &phone_no) {
            contact[name] = phone_no;
        }
        bool remove_contact(const std::string &name) {
            auto del_contact = contact.erase(name);
            if(del_contact > 0) {
                return true;        //contact deleted
            }
            else {
                return false;       //contact not deleted
            }
        }
        auto get_number(const std::string &name) const {
            auto it = contact.find(name);
            if(it != contact.end()) {
                return it->second;
            }
            std::cout << "Not found\n";
        }
        std::map<std::string, long long> get_AllContacts() const {
            return contact;
        }
};

PYBIND11_MODULE(phonebook,m) {
    m.doc() = "Phonebook with cpp as backend";
    py::class_<Phonebook>(m, "Phonebook")
        .def(py::init<>())   //default constructor
        .def(py::init<const std::map<std::string, long long>&>())
        .def("add_contact", &Phonebook::add_contact)
        .def("remove_contact", &Phonebook::remove_contact)
        .def("get_number", &Phonebook::get_number)
        .def("get_AllContacts", &Phonebook::get_AllContacts);

}
