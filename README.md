# Interview_Algorithm

### 字符串比较函数
####C：

* char st[100];

-- 1. 字符串长度

```
   strlen(st);
```

-- 2. 字符串比较

```
   strcmp(st1,st2); // 相等返回0，s1<s2返回负数，反之正数
   strncmp(st1,st2,n);   把st1,st2的前n个进行比较。
```
-- 3. 附加(连接)

```
   strcat(st1,st2); // 结果放到st1中
   strncat(st1,st2,n);   n表示连接上st2的前n个给st1，在最后不要加'\0'。
```
-- 4. 替换(复制)

```
   strcpy(st1,st2);
   strncpy(st1,st2,n); n表示复制st2的前n个给st1，在最后要加'\0'。
``` 

-- 5. 查找

```
   where = strchr(st,ch)   ch为要找的字符。
   where = strspn(st1,st2); 查找字符串。
```

####C++：

```
<string>

string str;
```

-- 1. 字符串长度

```
   len = str.length();
   len = str.size();
```
-- 2. 字符串比较

```
   可以直接比较
   也可以:
   str1.compare(str2); 
   str1.compare(pos1,len1,str2,pos2,len2); 值为负，0 ，正。
   nops 长度到完。
```
-- 3. 附加

```
   str1 += str2;
   或
   str1.append(str2);
   str1.append(str2.pos2,len2);
```
-- 4. 字符串提取

```
   str2 = str1.substr();
   str2 = str1.substr(pos1);
   str2 = str1.substr(pos1,len1);
```
-- 5. 字符串搜索

```
   where = str1.find(str2);
   where = str1.find(str2,pos1); pos1是从str1的第几位开始。
   where = str1.rfind(str2); 从后往前搜。
```
-- 6. 插入字符串

```
   不是赋值语句。
   str1.insert(pos1,str2);
   str1.insert(pos1,str2,pos2,len2);
   str1.insert(pos1,numchar,char); numchar是插入次数，char是要插入的字符。
```
-- 7. 替换字符串

```
   str1.replace(pos1,str2);
   str1.replace(pos1,str2,pos2,len2);
```
-- 8. 删除字符串

```
   str.erase(pos,len)
   str.clear();
```
-- 9. 交换字符串

```
   swap(str1,str2);
```
-- 10. C --> C++

```
   char *cstr = "Hello";
   string str1;
   cstr = cstr;
   string str2(cstr); 
```
