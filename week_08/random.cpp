while ( !is_this_the_right_student(buffer[key],f,l) )
            key = (key + 1)%BUFFLEN;
        
        return buffer[key];

bool is_this_the_right_student(student s , string f, string l){
        return ((s.first==f) && (s.last==l));
    }