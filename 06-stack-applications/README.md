[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/p5ahTw45)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=18868395&assignment_repo_type=AssignmentRepo)
# Stack хэрэглээ

Энэхүү ажлаар stack өгөгдлийн бүтцийн зарим хэрэглээг судлах болно. Доорх гурван програмыг хэрэгжүүлэхийн тулд өмнө хэрэгжүүлж байсан linked list болон linked stack-н кодыг `include/linked_list.c`, `include/linked_stack.c` файлд тус тус оруулаарай.

## Хаалт шалгагч

Хаалт шалгагч нь өгөгдсөн хаалтуудын дарааллыг шалгаж бүх хаалт зөв нээгдэж, хаагдсан эсэхийг шалгана.

Жишээ нь:

- `{[(())]}` бол алдаагүй тул `ALDAAGUI` гэж хэвлэнэ.
- `{[(())}` бол алдаатай буюу `[` хаалт хаагдаагүй тул `ALDAATAI` гэж хэвлэнэ.

**Хэрэгжүүлэлт хийх файл:** `brackets.c`

**Compile команд (Windows):** `gcc brackets.c include/linked_list.c include/linked_stack.c -o brackets.exe`

## Аравтаас хоёртын тооллын системд хөрвүүлэгч

Аравтын тооллын системийн тоо өгөхөд түүнийг хоёртын тооллын системд хөрвүүлэн хэвлэнэ.

Жишээ нь:

- `127` оруулахад `111111`
- `2024` оруулахад `11111101000` гэх мэт хэвлэх.

**Хэрэгжүүлэлт хийх файл:** `dec2bin.c`

**Compile команд (Windows):** `gcc dec2bin.c include/linked_list.c include/linked_stack.c -o dec2bin.exe`

## Infix-г Postfix руу хөрвүүлэгч

Infix буюу илэрхийллийн үйлдэл нь үйлдэл хийх хоёр тооны дунд байрлах (`1 + 2 / 3`) буюу бидний ихэвчлэн бичдэг дүрслэл юм. Харин postfix нь үйлдлийн тэмдэг хоёр тооны ард байрлах (`3 2 1 + /`) бөгөөд компьютер үйлдлийн тэмдгийн эрэмбийн ялгаатай илэрхийлэл бодоход хэрэглэдэг тэмдэглэгээ юм.

**Энэхүү даалгавар нь хоёр хэсэгтэй:**

1. `infix2postfix` функцийг хэрэгжүүлэх. Энэ функц нь infix хэлбэрээр бичигдсэн илэрхийллийг postfix хэлбэрт хөрвүүлнэ. `2+3*4` илэрхийлэл оруулахад `2 3 4 * +` гэсэн үр дүн гарах ёстой.
2. Postfix хэлбэрт хөрвүүлсэн илрэхийллийг бодох. Өмнөх алхамд хөрвүүлсэн илэрхийлэл болох `2 3 4 * +` илэрхийллийг stack-н тусламжтай бодож, илэрхийллийн хариу болох `14`-ийг тооцоолж олно.

Даалгаврыг хялбарчлах үүднээс програмын оролтын илэрхийлэл зөвхөн нэг оронтой тоо бөгөөд `+-*/()` үйлдлийн тэмдгээс бүрдэнэ.

Жишээ нь дээр үзүүлсэн нэг илэрхийллийн хоёр дүрслэлийг харж болно.

**Хэрэгжүүлэлт хийх файл:** `infix2postfix.c`

**Compile команд (Windows):** `gcc infix2postfix.c include/linked_list.c include/linked_stack.c -o infix2postfix.exe`

