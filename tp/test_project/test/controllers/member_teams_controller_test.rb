require 'test_helper'

class MemberTeamsControllerTest < ActionDispatch::IntegrationTest
  setup do
    @member_team = member_teams(:one)
  end

  test "should get index" do
    get member_teams_url
    assert_response :success
  end

  test "should get new" do
    get new_member_team_url
    assert_response :success
  end

  test "should create member_team" do
    assert_difference('MemberTeam.count') do
      post member_teams_url, params: { member_team: { member_id: @member_team.member_id, team_id: @member_team.team_id } }
    end

    assert_redirected_to member_team_url(MemberTeam.last)
  end

  test "should show member_team" do
    get member_team_url(@member_team)
    assert_response :success
  end

  test "should get edit" do
    get edit_member_team_url(@member_team)
    assert_response :success
  end

  test "should update member_team" do
    patch member_team_url(@member_team), params: { member_team: { member_id: @member_team.member_id, team_id: @member_team.team_id } }
    assert_redirected_to member_team_url(@member_team)
  end

  test "should destroy member_team" do
    assert_difference('MemberTeam.count', -1) do
      delete member_team_url(@member_team)
    end

    assert_redirected_to member_teams_url
  end
end
