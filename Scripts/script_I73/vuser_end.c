vuser_end()
{
	lr_start_transaction("TR06_Sign_Off");

	web_url("welcome.pl_2", 
		"URL=http://localhost:8070/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8070/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("TR06_Sign_Off",LR_AUTO);
	
	return 0;
}
