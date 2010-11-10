/*
 * YAFFS: Yet another FFS. A NAND-flash specific file system.
 *
 * Copyright (C) 2002-2010 Aleph One Ltd.
 *   for Toby Churchill Ltd and Brightstar Engineering
 *
 * Created by Timothy Manning <timothy@yaffs.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include "test_yaffs_open_ENOTDIR.h"


int test_yaffs_unlink_ENOTDIR(void){
	int output=0;
	int error_code=0;
	/*printf("path %s\n",path); */
	output=yaffs_unlink("/nonexisting_dir/foo");
	if (output==-1){
		error_code=yaffs_get_error();
		//printf("EISDIR def %d, Error code %d\n", ENOTDIR,error_code);
		if (abs(error_code)==ENOTDIR){
			return 1;
		}
		else {
			printf("different error than expected\n");
			return -1;
		}
	}
	else {
		printf("non existant directory opened.(which is a bad thing)\n");
		return -1;
	}


}
int test_yaffs_unlink_ENOTDIR_clean(void){
	return 1;
}
