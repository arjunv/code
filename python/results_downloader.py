# -*- coding: utf-8 -*-
"""University of Calicut Results Downloader
Author: arjun v
Usage:
        $ python downloader.py
Args:   None
Returns: None
Output: Results are downloaded and saved in the running location
        under directory `exam_name` as file `student_id.pdf`
"""

import os
import re
import socket
import urllib
import urllib2
from cookielib import CookieJar
from random import randint

# Let the games begin!
def lets_begin():
    try:
        exam_list = exam_list_downloader(4) # Change value to change course
        exam_selected = show_options(exam_list)-1
        exam_id = exam_list[exam_selected][0]
        exam_name = exam_list[exam_selected][1]
        print '\nDownloading results for \"' + exam_name + '\"!'
        for student in student_list():
            pdf_downloader(student,exam_id,exam_name)
        lets_begin()
    except KeyboardInterrupt:
        exit = str(raw_input('\n\nOops! Someone tried to break out! Are you sure? Y/N: '))
        if exit=='Y' or exit=='y':
            print 'Hope I worked! Else mail me at arjunvkp[at]gmail[.]com\nBye!'
        else:
            lets_begin()

# Generate List of Student ID's
def student_list():
    """
    This guy helps you generate list of Student IDs to download
    Usage:
        Expects clean inputs, except for case, which is automatically lowered
    Args: none
    Returns:
        list: List of Student IDs
    """
    list = []
    dpt = raw_input('Enter Student Category (Eg: JYAKEIT): ')
    id = int(raw_input('Enter First Student\'s ID (Eg: 1): '))
    id_end = int(raw_input('Enter Last Student\'s ID (Eg: 28): '))
    for i in range(0,id_end-id+1):
        list.append(str(dpt).lower() + str('{0:03d}'.format(id)))
        id = id + 1
    return list

# Display list of available exams
def show_options(exam_list):
    """
    This guy helps you choose which exam's result to download.
    Args:
        exam_list: List of Exams as Exam ID, Exam Name
    Returns:
        choice: User Choice
    """
    i = 1
    print '\nChoice > Exam ID -  Exam Name'
    for exm in exam_list:
        print '  ', i, '  >  ', exm[0], ' - ', exm[1]
        i = i+1
    while 1:
        choice = input('Select a choice from the exams list: ')
        if choice>0 and choice<i:
            return choice   # User input accepted
        print 'Try again! ',
# End of User Input Function

# Start of Exam List Downloader
def exam_list_downloader(txtcource = 4):
    """
    This guy lists the exam ids of results available for downloading
    Args:
        txtcource: University Course
                    default value: 4 (B.Tech)
    Returns:
        lst: Lists of exam id and exam name of results available for downloading
    """

# Set URL for retrieving list of exam results in the selected Course.
    url_list = 'http://202.88.252.21/CuPbhavan/curesultonline.php?txtcourse=%d' % txtcource
# Magic regex for finding urls and exam ids
    regex = re.compile('.+?res\_newregentry\.php\?id\=(.+?)\'.+?=2>(.+?)</a>')

# Retrieve list of exams and exam ids from the server
    try:
        list_req = urllib2.urlopen(url_list, timeout = 10)
    except urllib2.URLError as e:
        print "Can't connect to the network! Are you connected to the Internet?\n"    # something's wrong with the url!
    except socket.timeout as e:
        print "Well, they might be down. %r" % e    # they're down!
    else:    # now comes the fun part
        list_page_resp = list_req.read()
        # print list_page_resp[0:100]   # Uncomment to look at the html response
        # Match, Catch and Cleanup
        lst = list(regex.findall(list_page_resp))
        lst = [tuple(map(lambda i: str.replace(i, "&nbsp;",""), tup)) for tup in lst]
        # print lst # Uncomment to see the retrieved list of exam results
        return lst
# End of exam_list_downloader

# Start of pdf_downloader
def pdf_downloader(register_number,exam_id,exam_name):
    """
    This guy downloads the requested pdf.
    Args:
        register_number:    Register number of the student
        exam_id:            UoC sets an id to every exam result it releases
        exam_name:          Name of the exam of which the results are downloaded
    Returns:
        Saves the pdf in the folder the script is running from, under subdirectory `exam_id`
        with name `register_number`.pdf
    """

# Creates a cookie aware page opener
    cj = CookieJar()
    opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))

# URL List - University of Calicut
    url_login = 'http://202.88.252.21/CuPbhavan/res_newregentry.php'
    # url_bypass = 'http://202.88.252.21/CuPbhavan/rs_newcheck.php'
    url_pdf = 'http://202.88.252.21/CuPbhavan/cubtech7/sugrres.php'

# Build post data to send to the server
    post_data = {
                'regno' : register_number,
                'sum' : randint(20,200),
                'id' : exam_id,
                'sessionok' : 'yes'
            }
    data = urllib.urlencode(post_data)

# Submit post data to login url and save response cookies to cookie jar
    try:
        opener.open(url_login, data, timeout = 10)
        # login_req = opener.open(url_login, data, timeout = 10)
    except urllib2.URLError as e:
        print "Can't connect to the network! Are you connected to the Internet?\n"    # something's wrong with the url!
    except socket.timeout as e:
        print "Well, they might be down. %r" % e    # surprise! surprise!
    else:    # all is well

# Uncomment to look at the HTML from the login page and the cookie
        # login_page_resp = login_req.read()
        # print login_page_resp[0:100]
        # for cookie in cj:
        #     print cookie.name, cookie.value

# Bypassing Intermediate URL
        # bypass_req = opener.open(url_bypass, timeout = 10)
# Turns out there's no need to visit this!
# Turns out that it's not only useless, it's vulnerable to sqli too, lol!

# Request the server for the pdf file
        try:
            pdf_request = opener.open(url_pdf, timeout = 30)
        except urllib2.URLError as e:
            print type(e)
        except socket.timeout as e:
            print "Server is down or taking too much time! %r" % e    # as they always are
        else:    # it worked! no idea how though!
        # Read pdf data from the server
            pdf_data = pdf_request.read()
            # print pdf_data[0:100]    # Uncomment to look at the pdf from the sugrrespt.php

        # Save the pdf into the folder exam_id under current folder.
            file_name = register_number + '.pdf'
            script_dir = os.path.dirname(os.path.abspath(__file__))
            dest_dir = os.path.join(script_dir, exam_name)
            try:
                os.makedirs(dest_dir)
            except OSError:
                pass # directory already exists
            save_path = os.path.join(dest_dir, file_name)
        # Uncomment and change this to decide where to save the downloaded pdfs.
            # save_path = 'C:/example/'
            with open(save_path, "wb") as code:
                code.write(pdf_data)
                print '\nSaved result of \"' +register_number+ '\" at \"' +dest_dir+ '\\' + file_name +'\"!'

lets_begin()
