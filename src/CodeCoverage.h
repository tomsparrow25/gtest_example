#ifndef CODE_COVERAGE_H
#define CODE_COVERAGE_H

class Sum
{
public:
    Sum() { };
    ~Sum() { };

    void setAValue(int A);
    void setBValue(int B);
    int executeSum(void);

private:
    int _A = 0;
    int _B = 0;
};

#endif //CODE_COVERAGE_H