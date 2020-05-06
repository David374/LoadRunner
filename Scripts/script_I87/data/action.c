Action()
{

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_cookie("SRCHUID=V=2&GUID=BC1B2B694F5D48DC8AE83884B683CA34&dmnchg=1; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("SRCHD=AF=NOFORM; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("SRCHUSR=DOB=20200430; DOMAIN=iecvlist.microsoft.com");

	web_add_header("UA-CPU", 
		"AMD64");

	web_url("iecompatviewlist.xml", 
		"URL=https://iecvlist.microsoft.com/IE11/1478281996/iecompatviewlist.xml", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(54);

	lr_start_transaction("TR01_Login");

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=128698.586796274zzVQQDDpffiDDDDDDQHVQpzAVDf", ENDITEM, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=39", ENDITEM, 
		"Name=login.y", "Value=7", ENDITEM, 
		LAST);

	lr_end_transaction("TR01_Login",LR_AUTO);

	lr_start_transaction("TR02_Flights");

	web_add_cookie("SRCHUID=V=2&GUID=BC1B2B694F5D48DC8AE83884B683CA34&dmnchg=1; DOMAIN=c.urs.microsoft.com");

	web_add_cookie("SRCHD=AF=NOFORM; DOMAIN=c.urs.microsoft.com");

	web_add_cookie("SRCHUSR=DOB=20200430; DOMAIN=c.urs.microsoft.com");

	lr_think_time(20);

	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=https://c.urs.microsoft.com/l1.dat?cw=637194112741176080&v=3&cv=9.11.18362.0&os=10.0.18362.0.0&pg=4A72F430-B40C-4D36-A068-CE33ADA5ADF9", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("TR02_Flights",LR_AUTO);

	web_custom_request("FormDateUpdate.class", 
		"URL=http://localhost:1080/WebTours/classes/FormDateUpdate.class", 
		"Method=HEAD", 
		"TargetFrame=", 
		"Resource=1", 
		"Referer=", 
		"Snapshot=t5.inf", 
		LAST);

	lr_think_time(5);

	lr_start_transaction("TR03_Find_Flight");

	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value=Portland", ENDITEM, 
		"Name=departDate", "Value=05/07/2020", ENDITEM, 
		"Name=arrive", "Value=Seattle", ENDITEM, 
		"Name=returnDate", "Value=08/08/2020", ENDITEM, 
		"Name=numPassengers", "Value=3", ENDITEM, 
		"Name=seatPref", "Value=Aisle", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=46", ENDITEM, 
		"Name=findFlights.y", "Value=7", ENDITEM, 
		LAST);

	lr_end_transaction("TR03_Find_Flight",LR_AUTO);

	lr_think_time(20);

	lr_start_transaction("TR04_Itinerary");

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("TR04_Itinerary",LR_AUTO);

	lr_think_time(23);

	lr_start_transaction("TR05_Sign_Off");

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("TR05_Sign_Off",LR_AUTO);

	return 0;
}