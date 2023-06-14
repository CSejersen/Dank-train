#pragma once

class MotorDriver{

public:
    MotorDriver();
    void forward(unsigned char speed);
    void backward(unsigned char speed);
    void stop();

private:

};
