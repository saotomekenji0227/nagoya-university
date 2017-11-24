#define EXTIO_SCAN_ASCII (*(volatile unsigned int *)0x0310)
#define EXTIO_SCAN_REQ (*(volatile unsigned int *)0x030c)
#define EXTIO_SCAN_STROKE (*(volatile unsigned int *)0x0308)

#define SCAN_STRORING (unsigned int)0xffffffff

#define EXTIO_PRINT_STROKE (*(volatile unsigned int *) 0x0300)
#define EXTIO_PRINT_ASCII  (*(volatile unsigned int *) 0x0304)

#define TRUE 	0x1
#define FALSE	0x0

unsigned int sosuu_check(unsigned int kouho);
unsigned int my_a2i();
void my_i2a();
void my_print();
void my_scan();

main() {
  unsigned int i;
  unsigned int k;
  unsigned int str1[16];
  unsigned int str2[16];

  /* "HELLO" $B$r(B print */
  str1[0] = 'H';  str1[1] = 'E';
  str1[2] = 'L';  str1[3] = 'L';
  str1[4] = 'O';  str1[5] = '\n';
  str1[6] = '\0';
  my_print(str1);

  while (1) {	
    /* "NUM=" $B$r(B print */
    str1[0] = 'N';  str1[1] = 'U';
    str1[2] = 'M';  str1[3] = '=';
    str1[4] = '\0';
    my_print(str1);

    /* $B%-!<%\!<%I$+$iF~NO$5$l$?J8;zNs!J?t;z!K$r(B str2[] $B$K5-21(B */
    my_scan(str2);

    /* "ECHO " $B$r(B print */
    str1[0] = 'E';	str1[1] = 'C';
    str1[2] = 'H';	str1[3] = 'O';
    str1[4] = ' ';	str1[5] = '\0';
    my_print(str1);

    /* str2[] $B$r(B print */
    my_print(str2);

    /* '\n' $B$r(B print */
    str1[0] = '\n';  str1[1] = '\0';
    my_print(str1);
    
    /* $BJ8;zNs!J?t;z!K(B srt2[] $B$r(B unsigned int $B$KJQ49(B */
    k = my_a2i(str2);
    
    for (i = 3; i <= k; i++) {
      /* $BAG?tH=Dj(B */
      if ( sosuu_check(i) ) {  
	/* unsigned int i $B$rJ8;zNs!J?t;z!K$KJQ49$7$F(B print */
	my_i2a(i);
      }
    }

    /* '\n' $B$r(B print */
    str1[0] = '\n';  str1[1] = '\0';
    my_print(str1);
  }
}

/* unsigned int kouho $B$NAG?tH=Dj$r9T$&4X?t(B */
/* $BAG?t$J$i(B TRUE $B$rJV$9(B */
/* $BAG?t$G$J$$$J$i(B FALSE $B$rJV$9(B */
unsigned int sosuu_check(unsigned int kouho) {
  unsigned int t, tester, result;
  unsigned int j;
  if ((kouho % 2) == 0) {
    /* kouho $B$O6v?t$G$"$k(B == TRUE */
    return FALSE;
  } else {
    result = TRUE;
    for (tester = 3; tester < kouho/2; tester += 2) {
      /* kouho $B$,K\Ev$KAG?t$+$I$&$+$r%A%'%C%/(B */
      for (j = tester; j <= kouho; j += tester)
	if (kouho == j) {
	  /* kouho $B$O(B tester $B$NG\?t$G$"$k(B */
	  result = FALSE;
	}
    }
    return result;
  }
}

/* $BJ8;zNs!J?t;z!K(B srt[] $B$r(B unsigned int $B$KJQ49$9$k4X?t(B */
/* unsigned int result $B$rJV$9(B */
unsigned int my_a2i(str)
     unsigned int *str;
{
  unsigned int *str_tmp;
  unsigned int k;
  unsigned int result;

  str_tmp = str;
  for (k = 0; *str_tmp != '\0'; k++) {
    str_tmp++;
  }

  result = 0;
  str_tmp = str;
  
  if (k == 1) {
    result = *str_tmp - '0';
  } else if (k == 2) {
    for (k = 0; k < (*str_tmp - '0'); k++) {
      result = result + 10;
    }
    str_tmp++;
    result = result + (*str_tmp - '0');
  } else if (k == 3) {
    for (k = 0; k < (*str_tmp - '0'); k++) {
      result = result + 100;
    }
    str_tmp++;
    for (k = 0; k < (*str_tmp - '0'); k++) {
      result = result + 10;
    }
    str_tmp++;
    result = result + (*str_tmp - '0');
  }

  return result;
}

/* unsigned int i $B$rJ8;zNs!J?t;z!K$KJQ49$7$F(B print $B$9$k4X?t(B */
void my_i2a(unsigned int i) {
  unsigned int counter;
  unsigned int s[4];

    for (counter = 0; i >= 10; counter++) {
        i -= 10;
    }
    s[0] = counter + '0';
    s[1] = i + '0';
    s[2] = ' ';
    s[3] = '\0';

    my_print(s);
}

/* $B%-!<%\!<%I$+$iF~NO$5$l$?J8;zNs$r(B str[] $B$K5-21$9$k4X?t(B */
void my_scan(str)
     unsigned int *str;
{
    EXTIO_SCAN_STROKE = (unsigned int)0x00000000;
    EXTIO_SCAN_REQ = (unsigned int)0x00000001;
    EXTIO_SCAN_STROKE = (unsigned int)0x00000001;

    EXTIO_SCAN_STROKE = (unsigned int)0x00000000;
    EXTIO_SCAN_STROKE = (unsigned int)0x00000001;
    while (EXTIO_SCAN_ASCII == SCAN_STRORING) {
      EXTIO_SCAN_STROKE = (unsigned int)0x00000000;
      EXTIO_SCAN_STROKE = (unsigned int)0x00000001;
    }

    while ((*str = EXTIO_SCAN_ASCII) != (unsigned int)0x3e) {    // 0x3e=RETURN
      if ((*str >= 1) && (*str <= 26)) {
	*str = 'A' + *str - 1;
      } else if ((*str >= 48) && (*str <= 57)) {
	*str = '0' + *str - 48;
      } else {
	if (*str == 0) {
	  *str = '@';
	  } else if (*str == 27) {
	  *str = '[';
	} else if (*str == 29) {
	  *str = ']';
	} else if ((*str >= 32) && (*str <= 47)) {
	  *str = ' ' + *str - 32;
	} else if (*str == 58) {
	  *str = '?';
	} else if (*str == 59) {
	  *str = '=';
	} else if (*str == 60) {
	  *str = ';';
	} else if (*str == 61) {
	  *str = ':';
	} else if (*str == 62) {
	  *str = '\n';
	} else {
	  *str = '@';
	}
      }
      EXTIO_SCAN_STROKE = (unsigned int)0x00000000;
      EXTIO_SCAN_STROKE = (unsigned int)0x00000001;
      str++;
    }
    *str = '\0';

    EXTIO_SCAN_STROKE = (unsigned int)0x00000000;
    EXTIO_SCAN_REQ = (unsigned int)0x00000000;
    EXTIO_SCAN_STROKE = (unsigned int)0x00000001;

    EXTIO_SCAN_STROKE = (unsigned int)0x00000000;
}

/* $BJ8;zNs(B str[] $B$rI=<($9$k4X?t(B */
void my_print(str)
     unsigned int *str;
{
  while (*str != '\0') {
    EXTIO_PRINT_STROKE = (unsigned int)0x00000000;

    if ((*str >= 'A') && (*str <= 'Z')) {
      EXTIO_PRINT_ASCII = *str - 'A' + 1;
    } else if ((*str >= 'a') && (*str <= 'z')) {
      EXTIO_PRINT_ASCII = *str - 'a' + 1;
    } else if ((*str >= '0') && (*str <= '9')) {
      EXTIO_PRINT_ASCII = *str - '0' + 48;
    } else {
      if (*str == '@') {
        EXTIO_PRINT_ASCII = (unsigned int)0;
      } else if (*str == '[') {
        EXTIO_PRINT_ASCII = (unsigned int)27;
      } else if (*str == ']') {
        EXTIO_PRINT_ASCII = (unsigned int)29;
      } else if ((*str >= ' ') && (*str <= '/')) {
        EXTIO_PRINT_ASCII = *str - ' ' + 32;
      } else if (*str == '?') {
        EXTIO_PRINT_ASCII = (unsigned int)58;
      } else if (*str == '=') {
        EXTIO_PRINT_ASCII = (unsigned int)59;
      } else if (*str == ';') {
        EXTIO_PRINT_ASCII = (unsigned int)60;
      } else if (*str == ':') {
        EXTIO_PRINT_ASCII = (unsigned int)61;
      } else if (*str == '\n') {
	EXTIO_PRINT_ASCII = (unsigned int)62;
      } else {
        EXTIO_PRINT_ASCII = (unsigned int)0x00000000;
      }
    }
   
    EXTIO_PRINT_STROKE = (unsigned int)0x00000001;
    str++;
  }
}

