#include "stdio.h"
#include "stdint.h"

extern "C"
{
    typedef struct __treeNode treeNode;
    struct __treeNode
    {
        int32_t value;
        // treeNode *leftTree, *rightTree;
    };

    typedef struct __testStruct testStruct;
    struct __testStruct
    {
        uint64_t v1;
        struct __treeNode root;
        union
        {
            uint64_t v2;
            struct
            {
                uint32_t v2L;
                uint32_t v2H;
            };
        };
    };

    // typedef struct
    // {
    //     testStruct *test;
    //     chainNode *next;
    // } chainNode;

    int main(int argc, char const *argv[])
    {
        testStruct t;
        uint32_t address1, address2;

        printf("size of 'treeNode' is %d\n", sizeof(treeNode));
        printf("size of 'testStruct' is %d\n", sizeof(testStruct));

        address1 = (uint32_t) & (t.v2);
        address2 = (uint32_t) & (t.v2L);
        printf("v2 and v2L: %d\n", address1 - address2);

        printf("add of t is: 0x%x\n", (uint32_t)(&t));
        printf("add of v1 is: 0x%x\n", (uint32_t)&(t.v1));
        printf("add of root is: 0x%x\n", (uint32_t)&(t.root));
        printf("add of v2 is: 0x%x\n", (uint32_t)&(t.v2));
    }
}