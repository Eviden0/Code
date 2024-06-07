<?php
$captcha = 0;
while (true) {
    if (substr(md5($captcha), -6, 6) == "538f89")   //bbaddc会变
    {
        echo $captcha;
        break;
    }
    $captcha++;


}
// echo urlencode("file:///flag");