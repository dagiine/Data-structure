[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/Ob0Qm9SY)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=18413592&assignment_repo_type=AssignmentRepo)
# Дараалал, Стек

Дараалал (queue), стек (stack) өгөгдлийн бүтцийг хүснэгт (array) болон холбоост (linked) байдлаар хэрэгжүүлнэ. Энд өмнө нь хэрэгжүүлсэн жагсаалтын кодоо хэрэглэж болох ба жагсаалтын хэрэгжүүлэлтээ `include/*.c` файлд оруулаарай.

## Даалгавар:

Жагсаалт даалгавраар хэрэгжүүлсэн `array_list.c`, `linked_list.c` кодыг хэрэглэх тул `include` дотор байрлуулсан эсэхээ шалгаарай.

### Queue

`array_queue.c`, `linked_queue.c` файлд тодорхойлсон элемент оруулах `enqueue`, элемент гаргах `dequeue` функцуудыг хэрэгжүүлнэ. `dequeue` функц элемент байхгүй бол `-1` буцаана.

### Stack

`array_stack.c`, `linked_stack.c` файлд тодорхойлсон элемент оруулах `push`, элемент гаргах `pop` функцуудыг хэрэгжүүлнэ. `pop` функц элемент байхгүй бол `-1` буцаана.

### main()

Дээрх 4 файлын `main` функц бүр нэг ижил давталттай, гараас тэмдэгт болон тоо унших үйлдэл гүйцэтгэнэ. Түүнийг өөрчилж болохгүйг анхаараарай.

Програмын ажиллагааны жишээ (`<--` болон хойшхи текст нь тайлбар болно):

```
+10  <-- 10 утгатай элемент нэмэх (enqueue, push)
+12  <-- 12 утгатай элемент нэмэх (enqueue, push)
+14  <-- 14 утгатай элемент нэмэх (enqueue, push)
-    <-- элемент хасах (dequeue, pop)
-    <-- элемент хасах (dequeue, pop)
```

