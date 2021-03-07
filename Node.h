#ifndef Node_h
#define Node_h
struct order{
    int order_number; // หมายเลขออร์เดอร์
    int queue; //จำนวน
    struct order *nextPtr;
};
typedef struct order Order;
typedef struct order * OrderPtr;
#endif
