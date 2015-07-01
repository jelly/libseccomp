/**
 * Seccomp Library test program
 *
 * Copyright (c) 2015 Red Hat <pmoore@redhat.com>
 * Author: Paul Moore <pmoore@redhat.com>
 */

/*
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of version 2.1 of the GNU Lesser General Public License as
 * published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, see <http://www.gnu.org/licenses>.
 */

#include <errno.h>
#include <unistd.h>

#include <seccomp.h>

#include "util.h"

int main(int argc, char *argv[])
{
	int rc;
	struct util_options opts;
	scmp_filter_ctx ctx = NULL;

	rc = util_getopt(argc, argv, &opts);
	if (rc < 0)
		goto out;

	ctx = seccomp_init(SCMP_ACT_ALLOW);
	if (ctx == NULL)
		return ENOMEM;

	rc = seccomp_rule_add_exact(ctx, SCMP_ACT_KILL, 1000, 1,
				    SCMP_A0(SCMP_CMP_EQ, 3));
	if (rc != 0)
		goto out;
	rc = seccomp_rule_add_exact(ctx, SCMP_ACT_KILL, 1000, 1,
				    SCMP_A0(SCMP_CMP_EQ, 4));
	if (rc != 0)
		goto out;
	rc = seccomp_rule_add_exact(ctx, SCMP_ACT_KILL, 1000, 1,
				    SCMP_A0(SCMP_CMP_EQ, 5));
	if (rc != 0)
		goto out;
	rc = seccomp_rule_add_exact(ctx, SCMP_ACT_KILL, 1000, 1,
				    SCMP_A0(SCMP_CMP_EQ, 6));
	if (rc != 0)
		goto out;
	rc = seccomp_rule_add_exact(ctx, SCMP_ACT_KILL, 1000, 1,
				    SCMP_A0(SCMP_CMP_EQ, 7));
	if (rc != 0)
		goto out;
	rc = seccomp_rule_add_exact(ctx, SCMP_ACT_KILL, 1000, 1,
				    SCMP_A0(SCMP_CMP_EQ, 8));
	if (rc != 0)
		goto out;
	rc = seccomp_rule_add_exact(ctx, SCMP_ACT_KILL, 1000, 1,
				    SCMP_A0(SCMP_CMP_EQ, 9));
	if (rc != 0)
		goto out;
	rc = seccomp_rule_add_exact(ctx, SCMP_ACT_KILL, 1000, 1,
				    SCMP_A0(SCMP_CMP_EQ, 11));
	if (rc != 0)
		goto out;
	rc = seccomp_rule_add_exact(ctx, SCMP_ACT_KILL, 1000, 1,
				    SCMP_A0(SCMP_CMP_EQ, 12));
	if (rc != 0)
		goto out;
	rc = seccomp_rule_add_exact(ctx, SCMP_ACT_KILL, 1000, 1,
				    SCMP_A0(SCMP_CMP_EQ, 13));
	if (rc != 0)
		goto out;
	rc = seccomp_rule_add_exact(ctx, SCMP_ACT_KILL, 1000, 1,
				    SCMP_A0(SCMP_CMP_EQ, 14));
	if (rc != 0)
		goto out;
	rc = seccomp_rule_add_exact(ctx, SCMP_ACT_KILL, 1000, 1,
				    SCMP_A0(SCMP_CMP_EQ, 15));
	if (rc != 0)
		goto out;
	rc = seccomp_rule_add_exact(ctx, SCMP_ACT_KILL, 1000, 1,
				    SCMP_A0(SCMP_CMP_GE, 16));
	if (rc != 0)
		goto out;

	rc = util_filter_output(&opts, ctx);
	if (rc)
		goto out;

out:
	seccomp_release(ctx);
	return (rc < 0 ? -rc : rc);
}
