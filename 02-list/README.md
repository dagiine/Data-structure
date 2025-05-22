[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/DKSSF_cT)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=18284436&assignment_repo_type=AssignmentRepo)
# Жагсаалт

Жагсаалт өгөгдлийн бүтцийг хүснэгт (array) болон холбоост (linked) жагсаалт байдлаар хэрэгжүүлнэ.

## Array List

`array_list.h` файлд тодорхойлсон `ArrayList` бүтэц төрлийн өгөгдлөөр жагсаалтыг дүрслэх бөгөөд `values`-д жагсаалтын утга, `max_size`-д жагсаалтад хадгалж болох дээд хэмжээ, `length`-д жагсаалтад хадгалсан (хэрэглэгдэж буй хэмжээ) элементийн тоог хадгална.

```mermaid
graph TB
    subgraph Values
        A1[0: 10]
        A2[1: 11]
        A3[2: 12]
        A4[3: null]
        A5[4: null]
    end

    subgraph ArrayList
        length[length: 3]
        max_size[max_size: 5]
        values --> |int*|Values
    end
```

## Linked List

`linked_list.h` файлд тодорхойлсон `Node` бүтэц төрлийн өгөгдлөөр жагсаалтыг дүрслэх бөгөөд `val`-д жагсаалтын утга, `next` заагчид дараагийн элементийн (Node) хаягийг хадгална. Хэрэв төгсгөлийн элемент бол `next` заагчийн утга `NULL` байна.

```mermaid
graph TD;
    A["Node (val: 10)"] --> B["Node (val: 11)"];
    B --> C["Node (val: 12)"];
    C --> D["NULL"];
```

## Даалгавар:

- `array_list.c` - `array_list.h` толгой файлд тодорхойлсон функцуудыг энэ файлд хэрэгжүүлнэ
- `linked_list.c` - `linked_list.h` толгой файлд тодорхойлсон функцуудыг энэ файлд хэрэгжүүлнэ
- `prog_array.c` - Хүснэгт жагсаалтаа шалгах кодоо энд бичиж болно
- `prog_linked.c` - Холбоост жагсаалтаа шалгах кодоо энд бичиж болно

**Санамж:** `array_list.h` болон `linked_list.h` файлуудад тодорхойлсон функц болон бүтэц төрлийг өөрчлөхгүй байх шаардлагатай. Нэмэлт функц хэрэгтэй гэвэл өөрсдөө бичиж болно. `prog_*` дотор жагсаалтаа хэрэглэх код бичихдээ `test` доторх `demo_array.c`, `demo_linked.c` файлаас жишээ авч болно, харин demo файлуудын агуулгыг өөрчилж болохгүй.

