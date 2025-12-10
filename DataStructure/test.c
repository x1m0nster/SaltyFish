#include"seqlist.h"

int main(void){
     Seqlist L;
    printf("===== Step 1: Init Seqlist =====\n");
    if (!Seqlist_Init(&L)) {
        printf("Init Seqlist failed!\n");
        return -1;
    }
    printf("Init Seqlist success, Maxsize=%d, length=%d\n", L.Maxsize, L.length);
    Seqlist_Print(&L); // 此时为空

    // 2. 测试插入功能（合法位置、超出范围位置）
    printf("\n===== Step 2: Test Insert =====\n");
    // 插入合法位置（pos=1）
    Seqlist_Insert(&L, 1, 10);
    // 插入合法位置（pos=2）
    Seqlist_Insert(&L, 2, 20);
    // 插入超出范围位置（pos=5，会自动修正为最后一位）
    Seqlist_Insert(&L, 5, 30);
    // 插入pos=0（非法，提示错误）
    Seqlist_Insert(&L, 0, 40);
    printf("After insert, length=%d\n", L.length);
    Seqlist_Print(&L); // 预期：10 20 30

    // 3. 测试按位置删除（合法位置、超出范围位置、传值/不传值）
    printf("\n===== Step 3: Test Delete by Pos =====\n");
    ElemType del_val;
    // 删除合法位置（pos=2），带回删除值
    Seqlist_DeletePos(&L, 2, &del_val);
    // 删除超出范围位置（pos=10，自动修正为最后一位）
    Seqlist_DeletePos(&L, 10, &del_val);
    // 删除pos=0（非法，提示错误）
    Seqlist_DeletePos(&L, 0, &del_val);
    // 删除时不传返回值（val=NULL）
    Seqlist_DeletePos(&L, 1, NULL);
    printf("After delete by pos, length=%d\n", L.length);
    Seqlist_Print(&L); // 此时应已清空

    // 4. 重新插入数据，测试按值删除
    printf("\n===== Step 4: Test Delete by Val =====\n");
    // 重新插入一批数据：10,20,10,30,10
    Seqlist_Insert(&L, 1, 10);
    Seqlist_Insert(&L, 2, 20);
    Seqlist_Insert(&L, 3, 10);
    Seqlist_Insert(&L, 4, 30);
    Seqlist_Insert(&L, 5, 10);
    printf("Before delete by val, ");
    Seqlist_Print(&L); // 10 20 10 30 10

    // 删除存在的值（val=10，删除所有10）
    Seqlist_DeleteVal(&L, 10);
    printf("After delete val=10, length=%d\n", L.length);
    Seqlist_Print(&L); // 预期：20 30

    // 删除不存在的值（val=99）
    Seqlist_DeleteVal(&L, 99);
    // 重新插入全为同一值的数据，测试删除所有值
    Seqlist_Insert(&L, 1, 5);
    Seqlist_Insert(&L, 2, 5);
    Seqlist_Insert(&L, 3, 5);
    printf("Before delete all val=5, ");
    Seqlist_Print(&L); // 20 30 5 5 5
    Seqlist_DeleteVal(&L, 5);
    printf("After delete all val=5, length=%d\n", L.length);
    Seqlist_Print(&L); // 预期：20 30

    // 5. 测试空表删除（边界场景）
    printf("\n===== Step 5: Test Delete on Empty List =====\n");
    // 先清空顺序表
    while (L.length > 0) {
        Seqlist_DeletePos(&L, 1, &del_val);
    }
    // 空表按位置删除
    Seqlist_DeletePos(&L, 1, &del_val);
    // 空表按值删除
    Seqlist_DeleteVal(&L, 10);

    printf("\n===== All Test Finished =====\n");
    return 0;
}