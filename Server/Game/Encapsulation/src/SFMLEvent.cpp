/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** Event
*/

#include "SFMLEvent.hpp"

Event::Event()
{
    #define SETKEY(x) this->_keys[#x] = sf::Keyboard::x;

    this->_event = std::make_shared<sf::Event>();
    SETKEY(Unknown);
    SETKEY(A);
    SETKEY(B);
    SETKEY(C);
    SETKEY(D);
    SETKEY(E);
    SETKEY(F);
    SETKEY(G);
    SETKEY(H);
    SETKEY(I);
    SETKEY(J);
    SETKEY(K);
    SETKEY(L);
    SETKEY(M);
    SETKEY(N);
    SETKEY(O);
    SETKEY(P);
    SETKEY(Q);
    SETKEY(R);
    SETKEY(S);
    SETKEY(T);
    SETKEY(U);
    SETKEY(V);
    SETKEY(W);
    SETKEY(X);
    SETKEY(Y);
    SETKEY(Z);
    SETKEY(Num0);
    SETKEY(Num1);
    SETKEY(Num2);
    SETKEY(Num3);
    SETKEY(Num4);
    SETKEY(Num5);
    SETKEY(Num6);
    SETKEY(Num7);
    SETKEY(Num8);
    SETKEY(Num9);
    SETKEY(Escape);
    SETKEY(LControl);
    SETKEY(LShift);
    SETKEY(LAlt);
    SETKEY(LSystem);
    SETKEY(RControl);
    SETKEY(RShift);
    SETKEY(RAlt);
    SETKEY(RSystem);
    SETKEY(Menu);
    SETKEY(LBracket);
    SETKEY(RBracket);
    SETKEY(SemiColon);
    SETKEY(Comma);
    SETKEY(Period);
    SETKEY(Quote);
    SETKEY(Slash);
    SETKEY(BackSlash);
    SETKEY(Tilde);
    SETKEY(Equal);
    SETKEY(Dash);
    SETKEY(Space);
    SETKEY(Return);
    SETKEY(BackSpace);
    SETKEY(Tab);
    SETKEY(PageUp);
    SETKEY(PageDown);
    SETKEY(End);
    SETKEY(Home);
    SETKEY(Insert);
    SETKEY(Delete);
    SETKEY(Add);
    SETKEY(Subtract);
    SETKEY(Multiply);
    SETKEY(Divide);
    SETKEY(Left);
    SETKEY(Right);
    SETKEY(Up);
    SETKEY(Down);
    SETKEY(Numpad0);
    SETKEY(Numpad1);
    SETKEY(Numpad2);
    SETKEY(Numpad3);
    SETKEY(Numpad4);
    SETKEY(Numpad5);
    SETKEY(Numpad6);
    SETKEY(Numpad7);
    SETKEY(Numpad8);
    SETKEY(Numpad9);
    SETKEY(F1);
    SETKEY(F2);
    SETKEY(F3);
    SETKEY(F4);
    SETKEY(F5);
    SETKEY(F6);
    SETKEY(F7);
    SETKEY(F8);
    SETKEY(F9);
    SETKEY(F10);
    SETKEY(F11);
    SETKEY(F12);
    SETKEY(F13);
    SETKEY(F14);
    SETKEY(F15);
    SETKEY(Pause);
}

Event::~Event()
{
}

sf::Keyboard::Key Event::stringToKey(std::string str)
{
    return this->_keys[str];
}

bool Event::isPressed(std::string keyCode)
{
    return sf::Keyboard::isKeyPressed(stringToKey(keyCode));
}

std::vector<ClientResponse> Event::getClientResponse() const
{
    return this->_clientResponses;
}

void Event::setClientResponses(std::vector<ClientResponse> clientResponses)
{
    this->_clientResponses = clientResponses;
}
